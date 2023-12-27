#include <iostream>

int main() {
    while (true) {
        std::string input;
        std::cin >> input;
        if (input == "end") {
            break;
        }

        char board[3][3];
        int x = 0, o = 0;
        for (int i = 0; i < 9; i++) {
            if (input[i] == 'X') {
                x++;
            } else if (input[i] == 'O') {
                o++;
            }
            board[i / 3][i % 3] = input[i];
        }

        bool x_win = false;
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == 'X' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                x_win = true;
            }
            if (board[0][i] == 'X' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                x_win = true;
            }
        }
        if (board[1][1] == 'X' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            x_win = true;
        }
        if (board[1][1] == 'X' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
            x_win = true;
        }

        bool o_win = false;
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == 'O' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                o_win = true;
            }
            if (board[0][i] == 'O' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                o_win = true;
            }
        }
        if (board[1][1] == 'O' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            o_win = true;
        }
        if (board[1][1] == 'O' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
            o_win = true;
        }

        if (x_win && !o_win && x - o == 1) {
            std::cout << "valid\n";
        } else if (!x_win && o_win && x == o) {
            std::cout << "valid\n";
        } else if (!x_win && !o_win && x == 5 && o == 4) {
            std::cout << "valid\n";
        } else {
            std::cout << "invalid\n";
        }
    }
    return 0;
}
