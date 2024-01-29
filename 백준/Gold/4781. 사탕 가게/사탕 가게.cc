#include <iostream>
#include <algorithm>

int N, M;
float f_M;
int calories[5005];
int prices[5005];
int dp[10010];

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
        }
        
        for (int i = 0; i < M + 1; i++) {
            dp[i] = 0;
        }

        for (int i = 1; i < M + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                if (i - prices[j] >= 0) {
                    dp[i] = std::max(dp[i], dp[i - prices[j]] + calories[j]);
                }
            }
        }

        std::cout << dp[M] << "\n";
    }
    return 0;
}