#include <iostream>

int N;
int order[1000001];
int dp[1000001];


int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    int maxLength = 0;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> order[i];
        dp[order[i]] = dp[order[i] - 1] + 1;
        maxLength = std::max(maxLength, dp[order[i]]);
    }

    std::cout << N - maxLength << "\n";

    return 0;
}
