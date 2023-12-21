#include <iostream>

int N;
long long dp[101];

int main() {
    std::cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    for (int i = 5; i < N + 1; i++) {
        dp[i] = std::max(dp[i - 1] + 1, std::max(dp[i - 3] * 2, std::max(dp[i - 4] * 3, dp[i - 5] * 4)));
    }

    std::cout << dp[N] << "\n";

    return 0;
}
