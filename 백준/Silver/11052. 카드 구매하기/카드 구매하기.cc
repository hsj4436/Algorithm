#include <iostream>

int N;
int cards[1001];
int dp[1001];


int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> cards[i];
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < i + 1; j++) {
            dp[i] = std::max(dp[i], dp[i - j] + cards[j]);
        }
    }

    std::cout << dp[N] << "\n";

    return 0;
}
