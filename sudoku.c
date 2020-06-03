#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int difficulty = 1;
int field[9][9];
int win = 0;

void main_menu(){
    system("cls");
    int choice;
    int n;
    printf("\n--------- Sudoku Game ----------\n"
           "\n"
           "1. New game\n"
           "2. Load game\n"
           "3. Level of difficulty\n"
           "4. Exit\n"
           "\n"
           "--------------------------------\n\n");
    printf("Choose a number: ");
    n = scanf("%d", &choice);
    fflush(stdin);
    if (n != 1){
        main_menu();
    }
    if ((choice < 1) || (choice > 4)){
        main_menu();
        return;
    }
    switch (choice){
        case 1:
            new_game();
            break;
        case 2:
            load_game();
            break;
        case 3:
            set_level();
            break;
        case 4:
            return 0;
    };
    main_menu();
}

void draw_field(){
    system("chcp 65001");
    system("cls");
    printf("\n");
    printf("     1   2   3   4   5   6   7   8   9\n");
    printf("   ╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
    int i;
    for (i = 0; i < 9; i++){
        int j;
        printf(" %d ║", i + 1);
        for (j = 0; j < 9; j++) {
            if (field[j][i] == 0) {
                printf("   ");
            } else {
                if (field[j][i] < 0) {
                    printf("\x1b[33m");
                }
                printf(" %d ", abs(field[j][i]));
                printf("\x1b[37m");
            }
            if ((j + 1) % 3 == 0) {
                printf("║");
            } else {
                printf("│");
            }
        }
        printf("\n");
        if ((i + 1) != 9) {
            if ((i + 1) % 3 == 0) {
                printf("   ╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
            } else {
                printf("   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
            }
        }
    }
    printf("   ╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝");
    if (win == 1) {
        printf("\n\n \x1b[92mYou win!\x1b[37m");
        getchar();
        main_menu();
    }
    /* fflush(stdin); */
    int n;
    int x, y, num;
    printf("\n\n Enter '0 0' to exit.\n");
    printf(" Enter (x; y) coordinates of the cell: ");
    n = scanf("%d %d", &x, &y);
    fflush(stdin);
    if (n != 2) {
        draw_field();
    }
    if ((x == 0) || (y == 0)) {
        return;
    }
    if ((x < 1) || (x > 9)) {
        draw_field();
    }
    if ((y < 1) || (y > 9)) {
        draw_field();
    }
    if (field[x - 1][y - 1] < 0) {
        draw_field();
    }
    printf(" Enter number to write in cell (%d; %d): ", x, y);
    n = scanf("%d", &num);
    fflush(stdin);
    if (n != 1) {
        draw_field();
    }
    if ((num < 1) || (num > 9)) {
        draw_field();
    }
    field[x - 1][y - 1] = num;
    int num_exists_row[9] = {0};
    win = 1;
    for (i = 0; i < 9; i++) {
        int j;
        for (j = 0; j < 9; j++) {
            int c_num = abs(field[j][i]);
            if (c_num != 0) {
                num_exists_row[c_num - 1]++;
            }
        }
        int k;
        for (k = 0; k < 9; k++) {
            if ((num_exists_row[k] > 1) || (num_exists_row[k] <= 0)) {
                win = 0;
                break;
            }
        }
        memset(num_exists_row, 0, sizeof(num_exists_row));
    }
    int num_exists_col[9] = {0};
    for (i = 0; i < 9; i++) {
        int j;
        for (j = 0; j < 9; j++) {
            int c_num = abs(field[i][j]);
            if (c_num != 0) {
                num_exists_col[c_num - 1]++;
            }
        }
        int k;
        for (k = 0; k < 9; k++) {
            if ((num_exists_col[k] > 1) || (num_exists_col[k] <= 0)) {
                win = 0;
                break;
            }
        }
        memset(num_exists_col, 0, sizeof(num_exists_col));
    }
    int num_exists_square[9] = {0};
    for (i = 0; i < 9; i++) {
        int j;
        for (j = 0; j < 9; j++) {
            int x, y;
            x = (j / 3);
            y = j - 3*x;
            int c_num = abs(field[x][y]);
            if (c_num != 0) {
                num_exists_square[c_num - 1]++;
            }
        }
        int k;
        for (k = 0; k < 9; k++) {
            if ((num_exists_square[k] > 1) || (num_exists_square[k] <= 0)) {
                win = 0;
                break;
            }
        }
        memset(num_exists_square, 0, sizeof(num_exists_square));
    }
    FILE *game_save;
    game_save = fopen("saved_game.txt", "w");
    for (i = 0; i < 9; i++) {
        int j;
        for (j = 0; j < 9; j++) {
            fprintf(game_save, "%d ", field[j][i]);
        }
    }
    fclose(game_save);
    draw_field();
    /*
    printf("%d ", win);
    getchar();
    */
    /*
    for (i = 0; i < 9; i++) {
        printf("%d ", num_exists2[i]);
    }
    getchar();
    */
}

void new_game(){
    printf("\nFeature in development...\n");
    /*
    int i1;
    for (i1 = 0; i1 < 9; i1++) {
        int j2;
        for (j2 = 0; j2 < 9; j2++) {
            field[i1][j2] = 0;
        }
    }
    */
    FILE *level_data;
    char c_num;
    char filename[11];
    switch (difficulty){
        case 1:
            strcpy(filename, "easy.txt");
            break;
        case 2:
            strcpy(filename, "medium.txt");
            break;
        case 3:
            strcpy(filename, "hard.txt");
            break;
    }
    level_data = fopen(filename, "r");
    /* printf("%s\n", filename); */

    int lines_count = 0;
    c_num = getc(level_data);
    while (c_num != EOF) {
        if (c_num == '\n') {
            lines_count += 1;
        }
        c_num = getc(level_data);
    }
    /* printf("%d\n", lines_count); */

    srand(time(NULL));
    int line_num = rand() % (lines_count + 1);
    /* printf("%d\n", line_num); */
    fseek(level_data, line_num * 83, SEEK_SET);
    int i;
    for (i = 0; i < 9; i++) {
        int j;
        for (j = 0; j < 9; j++) {
            c_num = fgetc(level_data);
            field[j][i] = -atoi(&c_num);
            /* printf("%d ", atoi(&c_num)); */
        }
    }
    fgetc(level_data);
    printf("\n");

    fclose(level_data);
    /* getchar(); */
    draw_field();
}

void load_game(){
    printf("\nFeature in development...\n");
    /* printf("Press any key..."); */

    FILE *game_save;
    char c_num;
    game_save = fopen("saved_game.txt", "r");
    int i;
    for (i = 0; i < 9; i++) {
        int j;
        for (j = 0; j < 9; j++) {
            fscanf(game_save, "%d", &field[j][i]);
        }
    }
    fclose(game_save);

    /* getchar(); */
    draw_field();
}

void set_level(){
    int level;
    int n;
    char level_str[10];
    switch (difficulty){
        case 1:
            strcpy(level_str, "Easy");
            break;
        case 2:
            strcpy(level_str, "Medium");
            break;
        case 3:
            strcpy(level_str, "Hard");
            break;
    }
    printf("\n--------------------------------\n"
           "\n"
           "Set level of difficulty:\n"
           "1. Easy\n"
           "2. Medium\n"
           "3. Hard\n"
           "\n"
           "Current level: %s.\n"
           "\n"
           "--------------------------------\n\n", level_str);
    printf("Choose a number: ");
    n = scanf("%d", &level);
    fflush(stdin);
    if (n != 1){
        set_level();
    }
    if ((level < 1) || (level > 5)){
        set_level();
    }
    difficulty = level;
}

int main(){
    main_menu();
    return 0;
}
