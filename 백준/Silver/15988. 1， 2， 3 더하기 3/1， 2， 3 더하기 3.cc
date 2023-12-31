#include <iostream>

int TC, N;
long long dp[1000001];

int main() {
    std::cin >> TC;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 1000001; i++) {
        dp[i] = (((dp[i - 1] + dp[i - 2]) % 1000000009) + dp[i - 3]) % 1000000009;
    }
    
    for (int tc = 0; tc < TC; tc++) {
        std::cin >> N;
        std::cout << dp[N] << "\n";
    }
    return 0;
}
