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
    for (int sy = 1; sy < M + 1; sy++) {
        for (int ey = sy; ey < M + 1; ey++) {
            for (int sx = 1; sx < N + 1; sx++) {
                for (int ex = sx; ex < N + 1; ex++) {
                    answer = std::max(answer, board[ex][ey] - board[sx - 1][ey] - board[ex][sy - 1] + board[sx - 1][sy - 1]);
                }
            }
        }
    }
    std::cout << answer << "\n";

    return 0;
}