#include <iostream>

int N, M;
int map[1002][1002];
int dp[1002][1002][3]; // from left, from up, from right

int main() {
    std::cin >> N >> M;

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            std::cin >> map[i][j];
        }
    }

    std::fill_n(&dp[0][0][0], 1002 * 1002 * 3, -987654321);
    dp[1][1][0] = map[1][1];
    dp[1][1][1] = map[1][1];
    dp[1][1][2] = map[1][1];
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            dp[i][j][0] = std::max(dp[i][j - 1][0], dp[i][j - 1][1]) + map[i][j];
            dp[i][j][1] = std::max(dp[i - 1][j][0], std::max(dp[i - 1][j][1], dp[i - 1][j][2])) + map[i][j];
        }
        if (i >= 2 && i < N) {
            for (int j = M; j > 0; j--) {
                dp[i][j][2] = std::max(dp[i][j + 1][1], dp[i][j + 1][2]) + map[i][j];
            }
        }
    }

    std::cout << std::max(dp[N][M][0], std::max(dp[N][M][1], dp[N][M][2]));
    return 0;
}
