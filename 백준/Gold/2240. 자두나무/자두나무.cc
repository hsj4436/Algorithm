#include <iostream>

int T, W;
int trees[1001];
int dp[1001][31][2];

int main() {
    std::cin >> T >> W;

    for (int i = 0; i < T; i++) {
        std::cin >> trees[i];
    }

    if (trees[0] == 1) {
        dp[0][W][0] = 1;
        dp[0][W - 1][0] = 1;
    } else {
        dp[0][W - 1][1] = 1;
    }

    for (int i = 1; i < T; i++) {
        for (int j = W; j > -1; j--) {
            if (trees[i] == 1) {
                if (j == W) {
                    dp[i][j][0] = std::max(dp[i][j][0], dp[i - 1][j][0] + 1);
                    dp[i][j][1] = std::max(dp[i][j][1], dp[i - 1][j][1]);
                } else {
                    dp[i][j][0] = std::max(dp[i - 1][j + 1][1] + 1, dp[i - 1][j][0] + 1);
                    dp[i][j][1] = std::max(dp[i][j][1], dp[i - 1][j][1]);
                }
            } else {
                if (j == W) {
                    dp[i][j][0] = std::max(dp[i][j][0], dp[i - 1][j][0]);
                    dp[i][j][1] = std::max(dp[i - 1][j][1], dp[i - 1][j][1] + 1);
                } else {
                    dp[i][j][0] = std::max(dp[i][j][0], dp[i - 1][j][0]);
                    dp[i][j][1] = std::max(dp[i - 1][j + 1][0] + 1, dp[i - 1][j][1] + 1);
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < W + 1; i++) {
        answer = std::max(dp[T - 1][i][0], std::max(dp[T - 1][i][1], answer));
    }

    std::cout << answer << "\n";

    return 0;
}
