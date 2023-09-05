#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random word from an array based on difficulty level
char* getRandomWord(int difficulty) {
    char* easyWords[5] = { "copy", "house", "chair", "book", "lamp" };
    char* mediumWords[5] = { "register", "coding", "workshop", "safeguard", "beauty" };
    char* hardWords[5] = { "exams", "challenging", "encryption", "algorithm", "complexity" };

    int index = rand() % 5;
    
    switch (difficulty) {
        case 1:
            return easyWords[index];
        case 2:
            return mediumWords[index];
        case 3:
            return hardWords[index];
        default:
            return easyWords[index];
    }
}

int main() {
    char name[100];
    printf("Enter Name: ");
    scanf("%s", name);
    printf("\n");
    int score = 0;
    char input;
    int difficulty;

    do {
        system("cls");

        printf("************************************CROSSWORD PUZZLE************************************\n");
        
        printf("Select Difficulty Level:\n");
        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &difficulty);

        srand(time(NULL));
        char* selectedWord = getRandomWord(difficulty);
        char* clues[5] = { "Duplicate", "Place to live", "Furniture item", "Reading material", "Source of light" };
        
        char puzzle[9][9];

        int i, j; // Declare i and j here
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                do {
                    puzzle[i][j] = rand() % 26 + 'a';
                } while (!(puzzle[i][j] >= 'a' && puzzle[i][j] <= 'z'));
            }
        }

        int r;
        int c;
        if (strlen(selectedWord) % 2 != 0) {
            r = rand() % 10;
            c = rand() % 1;
            int x;
            for (x = 0, c; selectedWord[x] != '\0'; x++, c++) {
                puzzle[r][c] = selectedWord[x];
            }
        } else {
            r = rand() % 2;
            c = rand() % 10;
            int x;
            for (x = 0, r; selectedWord[x] != '\0'; x++, r++) {
                puzzle[r][c] = selectedWord[x];
            }
        }

        printf("\nClue: %s\n", clues[difficulty - 1]);
        printf("\n");
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                printf("%c ", puzzle[i][j]);
            }
            printf("\n");
        }

        char answer[100];
        printf("\nEnter word that is of length %lu\n", strlen(selectedWord));
        scanf("%s", answer);
        if (strcmp(answer, selectedWord) == 0) {
            score = score + 1;
            printf("You won!!!\n");
        } else {
            printf("You lost!!!\n");
        }

        printf("Play again? (y/n)");
        scanf(" %c", &input);

    } while (input != 'n');

    printf("****************************GAME OVER****************************\n");
    printf("%s\nYour score is: %d\n\n\n\n", name, score);
    return 0;
}

