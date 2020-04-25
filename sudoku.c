#include <stdio.h>
#include <string.h>

int difficulty = 1;

void main_menu(){
    int choice;
    int n;
    printf("\n--------- Sudoku Game ----------\n"
           "\n"
           "1. New game\n"
           "2. Load game\n"
           "3. Level of difficulty\n"
           "4. Statistics\n"
           "5. Exit\n"
           "\n"
           "--------------------------------\n\n");
    printf("Choose a number: ");
    n = scanf("%d", &choice);
    fflush(stdin);
    if (n != 1){
        main_menu();
    }
    if ((choice < 1) || (choice > 5)){
        main_menu();
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
            statictics();
            break;
        case 5:
            return 0;
    };
    main_menu();
}

void new_game(){
    printf("\nFeature in development...\n");
}

void load_game(){
    printf("\nFeature in development...\n");
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

void statictics(){
    printf("\nFeature in development...\n");
}

int main(){
    main_menu();
    return 0;
}
