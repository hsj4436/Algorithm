#include <iostream>

#define LL long long
#define INF 10000000000

int N;
LL stones[5001];
LL dp[5001];

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> stones[i];
        dp[i] = INF;
    }

    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = std::min(dp[i], std::max(dp[j], (i - j) * (1 + std::abs(stones[i] - stones[j]))));
        }
    }

    std::cout << dp[N - 1] << "\n";
    return 0;
}
