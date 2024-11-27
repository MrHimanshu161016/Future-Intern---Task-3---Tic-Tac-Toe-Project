#include <stdio.h>

// CP-> Current Player
// B -> Board

#define Size 3

void printBoard(char B[Size][Size]) {
    printf("\n");

    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            printf(" %c ", B[i][j]);
            if (j < Size - 1) {
                printf("|");
            }
        }
        printf("\n");

        if (i < Size - 1) {
              printf("---|---|---\n");
        }
    }
    printf("\n");
}

int checkWin(char B[Size][Size]) {
    for (int i = 0; i < Size; i++) 
        if ((B[i][0] == B[i][1] && B[i][1] == B[i][2] && B[i][0] != ' ') || (B[0][i] == B[1][i] && B[1][i] == B[2][i] && B[0][i] != ' ')){
             return 1;
        }
            
    return (B[0][0] == B[1][1] && B[1][1] == B[2][2] && B[0][0] != ' ') || (B[0][2] == B[1][1] && B[1][1] == B[2][0] && B[0][2] != ' ');
           
}

int main() {
    char B[Size][Size] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int r, c, number_Of_Moves = 0, CP = 1;

    while (1) {
        printBoard(B);
        printf("Player %d, enter row and column (1-3): ", CP);
        scanf("%d %d", &r, &c);

        if (r < 1 || r > 3 || c < 1 || c > 3 || B[r-1][c-1] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        B[r-1][c-1] = (CP == 1) ? 'X' : 'O';
        number_Of_Moves++;

        if (checkWin(B)) {
            printBoard(B);
            printf("Player %d wins!\n", CP);
            break;
        }

        if (number_Of_Moves == 9) {
            printBoard(B);
            printf("It's a draw!\n");
            break;
        }

        CP = 3 - CP;
    }

    return 0;
}
