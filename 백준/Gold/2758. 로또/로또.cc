#include <iostream>
#include <math.h>

int T, N, M;
long long dp[2001][11];

int main() {
    std::cin >> T;

    for (int i = 1; i < 2001; i++) {
        for (int j = 1; j < 11; j++) {
            if (j == 1) {
                dp[i][j] = 1;
                continue;
            }
            if (i < std::pow(2, j - 1)) {
                break;
            }
            for (int k = 1; k < i / 2 + 1; k++) {
                dp[i][j] += dp[k][j - 1];
            }
        }
    }

    for (int t = 0; t < T; t++) {
        std::cin >> N >> M;

        long long sum = 0;
        for (int i = 1; i < M + 1; i++) {
            sum += dp[i][N];
        }
        std::cout << sum << "\n";
    }

    return 0;
}