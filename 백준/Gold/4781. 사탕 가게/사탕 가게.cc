#include <iostream>
#include <algorithm>

int N, M;
float f_M;
int calories[5005];
int prices[5005];
int dp[5005][10010];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    while (true) {
        std::cin >> N >> f_M;
        if (N == 0 && f_M == 0.00f) {
            break;
        }

        M = (int)(f_M * 100 + 0.5);
        float p;
        for (int i = 1; i < N + 1; i++) {
            std::cin >> calories[i] >> p;
            prices[i] = (int)(p * 100.0 + 0.5);
            for (int j = 0; j < M + 1; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i < N + 1; i++) {
            for (int j = 0; j < M + 1; j++) {
                if (j - prices[i] >= 0) {
                    dp[i][j] = std::max(dp[i][j], std::max(dp[i - 1][j - prices[i]] + calories[i], dp[i][j - prices[i]] + calories[i]));
                }
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
            }
        }

        int answer = 0;
        for (int i = 1; i < N + 1; i++) {
            answer = std::max(answer, dp[i][M]);
        }
        std::cout << answer << "\n";
    }
    return 0;
}