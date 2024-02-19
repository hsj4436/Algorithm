#include <iostream>

int T, N;
int dp[10001];

int main() {
    std::cin >> T;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    for (int i = 6; i < 10001; i++) {
        dp[i] = dp[i - 3] + i / 2 + 1;
    }

    while (T--) {
        std::cin >> N;
        std::cout << dp[N] << "\n";
    }
    return 0;
}
