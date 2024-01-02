#include <iostream>

int N, M, K;
char board[2001][2001];
int sum[2001][2001][2]; // 0 - black, 1 - white

int main() {
    std::cin >> N >> M >> K;

    for (int i = 1; i < N + 1; i++) {
        std::string row;
        std::cin >> row;
        for (int j = 1; j < M + 1; j++) {
            board[i][j] = row[j - 1];
            if ((i + j) % 2 == 0) {
                if (board[i][j] == 'B') {
                    sum[i][j][0] = sum[i - 1][j][0] + sum[i][j - 1][0] - sum[i - 1][j - 1][0];
                    sum[i][j][1] = sum[i - 1][j][1] + sum[i][j - 1][1] - sum[i - 1][j - 1][1] + 1;
                } else {
                    sum[i][j][0] = sum[i - 1][j][0] + sum[i][j - 1][0] - sum[i - 1][j - 1][0] + 1;
                    sum[i][j][1] = sum[i - 1][j][1] + sum[i][j - 1][1] - sum[i - 1][j - 1][1];
                }
            } else {
                if (board[i][j] == 'W') {
                    sum[i][j][0] = sum[i - 1][j][0] + sum[i][j - 1][0] - sum[i - 1][j - 1][0];
                    sum[i][j][1] = sum[i - 1][j][1] + sum[i][j - 1][1] - sum[i - 1][j - 1][1] + 1;
                } else {
                    sum[i][j][0] = sum[i - 1][j][0] + sum[i][j - 1][0] - sum[i - 1][j - 1][0] + 1;
                    sum[i][j][1] = sum[i - 1][j][1] + sum[i][j - 1][1] - sum[i - 1][j - 1][1];
                }
            }
        }
    }

    int answer = 4000001;
    for (int i = 1; i <= N + 1 - K; i++) {
        for (int j = 1; j <= M + 1 - K; j++) {
            int b_case = sum[i + K - 1][j + K - 1][0] - sum[i + K - 1][j - 1][0] - sum[i - 1][j + K - 1][0] + sum[i - 1][j - 1][0];
            int w_case = sum[i + K - 1][j + K - 1][1] - sum[i + K - 1][j - 1][1] - sum[i - 1][j + K - 1][1] + sum[i - 1][j - 1][1];
            answer = std::min(answer, std::min(b_case, w_case));
        }
    }

    std::cout << answer << "\n";

    return 0;
}
