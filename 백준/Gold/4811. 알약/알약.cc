#include <iostream>

int N;
long long dp[31];

long long sol(int n) {
    if (n <= 1) {
        return 1;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = 0;
    for (int i = 0; i < n; i++) {
        dp[n] += sol(i) * sol(n - i - 1);
    }

    return dp[n];
}

int main() {
    std::fill(dp, dp + 31, -1);
    while (true) {
        std::cin >> N;

        if (N == 0) {
            break;
        }

        std::cout << sol(N) << "\n";
    }
    return 0;
}