#include <iostream>

int c[501];
int dp[501][501];
int sum[501];

int main() {
    int tc = 0;
    std::cin >> tc;
    while (tc--) {
        int k = 0;
        std::cin >> k;
        for(int i = 1; i < k + 1; i++){
            std::cin >> c[i];
            sum[i] = sum[i - 1] + c[i];
        }

        for(int a = 1; a < k + 1; a++){
            for(int b = 1; b <= k - a; b++){
                dp[b][a + b] = 1000000000;
                for(int c = b; c < a + b; c++){
                    dp[b][a + b] = std::min(dp[b][a + b], dp[b][c] + dp[c + 1][a + b] + sum[a + b] - sum[b - 1]);
                }
            }
        }

        std::cout << dp[1][k] << "\n";

        for(int i = 1; i < k + 1; i++){
            c[i] = 0;
            sum[i] = 0;
            for(int j = 1; j < k + 1; j++){
                dp[i][j] = 0;
            }
        }
    }
    return 0;
}
