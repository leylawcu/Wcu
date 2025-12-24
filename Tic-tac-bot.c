#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];

void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

int checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return 1;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return 1;
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return 1;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return 1;

    return 0;
}

int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

void playerMove() {
    int r, c;
    do {
        printf("Sətir və sütun daxil et (0-2): ");
        scanf("%d %d", &r, &c);
    } while (r < 0 || r > 2 || c < 0 || c > 2 || board[r][c] != ' ');

    board[r][c] = 'X';
}

void botMove() {
    int r, c;
    do {
        r = rand() % 3;
        c = rand() % 3;
    } while (board[r][c] != ' ');

    board[r][c] = 'O';
    printf("Bot oynadı: %d %d\n", r, c);
}

int main() {
    srand(time(NULL));
    initBoard();

    while (1) {
        printBoard();
        playerMove();

        if (checkWin('X')) {
            printBoard();
            printf("🎉 Siz qalib gəldiniz!\n");
            break;
        }

        if (isDraw()) {
            printBoard();
            printf("🤝 Heç-heçə!\n");
            break;
        }

        botMove();

        if (checkWin('O')) {
            printBoard();
            printf("🤖 Bot qalib gəldi!\n");
            break;
        }
    }

    return 0;
}
