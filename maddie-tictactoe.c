#include <stdio.h>

void print_board(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

int winner(char b[3][3], char p) {
    for (int i = 0; i < 3; i++) {
        if (b[i][0] == p && b[i][1] == p && b[i][2] == p) return 1;
        if (b[0][i] == p && b[1][i] == p && b[2][i] == p) return 1;
    }
    if (b[0][0] == p && b[1][1] == p && b[2][2] == p) return 1;
    if (b[0][2] == p && b[1][1] == p && b[2][0] == p) return 1;
    return 0;
}

int main(void) {
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char player = 'X';
    int move, row, col, turns = 0;

    printf("=== TIC-TAC-TOE ===\n");
    while (turns < 9) {
        print_board(board);
        printf("Player %c, choose position (1-9): ", player);
        if (scanf("%d", &move) != 1) return 1;
        if (move < 1 || move > 9) {
            printf("Invalid position.\n");
            continue;
        }

        row = (move - 1) / 3;
        col = (move - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("That position is already taken.\n");
            continue;
        }

        board[row][col] = player;
        turns++;
        if (winner(board, player)) {
            print_board(board);
            printf("Player %c wins!\n", player);
            return 0;
        }
        player = (player == 'X') ? 'O' : 'X';
    }

    print_board(board);
    printf("It's a draw!\n");
    return 0;
}