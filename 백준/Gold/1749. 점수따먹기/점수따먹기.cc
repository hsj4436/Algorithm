#include <iostream>

int N, M;
int board[201][201];

int main() {
    std::cin >> N >> M;

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            std::cin >> board[i][j];
            board[i][j] += board[i][j - 1] + board[i - 1][j] - board[i - 1][j - 1];
        }
    }

    int answer = -987654321;
    for (int i = 1; i < M + 1; i++) {
        for (int j = i; j < M + 1; j++) {
            for (int a = 1; a < N + 1; a++) {
                for (int b = a; b < N + 1; b++) {
                    answer = std::max(answer, board[b][j] - board[b][i - 1] - board[a - 1][j] + board[a - 1][i - 1]);
                }
            }
        }
    }
    std::cout << answer << "\n";

    return 0;
}