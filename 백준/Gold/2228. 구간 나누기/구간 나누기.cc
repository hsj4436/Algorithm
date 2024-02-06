#include <iostream>

int N, M;
int sum[101];
int dp[102][52];

int main() {
    std::cin >> N >> M;


    for (int i = 1; i < N + 1; i++) {
        std::cin >> sum[i];
        sum[i] += sum[i - 1];
    }

    for (int i = 1; i < M + 1; i++) {
        dp[0][i] = -32769 * 101;
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k < i + 1; k++) {
                if (k >= 2) {
                    dp[i][j] = std::max(dp[i][j], dp[k - 2][j - 1] + sum[i] - sum[k - 1]);
                } else if (k == 1 && j == 1) {
                    dp[i][j] = std::max(dp[i][j], sum[i]);
                }
            }
        }
    }

    std::cout << dp[N][M] << "\n";

    return 0;
}