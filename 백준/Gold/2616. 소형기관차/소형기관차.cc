#include <iostream>

int N, M;
int train[50001];
int dp[50001][3];

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> train[i];
        train[i] += train[i - 1];
    }

    std::cin >> M;

    for (int i = 1; i < N + 1 - M + 1; i++) {
        dp[i][0] = std::max(dp[i - 1][0], train[i + M - 1] - train[i - 1]);
        if (i - M >= 1) {
            dp[i][1] = std::max(dp[i - 1][1], dp[i - M][0] + train[i + M - 1] - train[i - 1]);
            dp[i][2] = std::max(dp[i - 1][2], dp[i - M][1] + train[i + M - 1] - train[i - 1]);
        } else {
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];
        }
    }

    int answer = 0;
    for (int i = 1; i < N + 1; i++) {
        answer = std::max(dp[i][2], answer);
    }

    std::cout << answer << "\n";

    return 0;
}
