#include <iostream>
#include <algorithm>

int N;
int cost[51];
int cost_sum = 0;
bool dp[2501][2501];

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> cost[i];
        cost_sum += cost[i];
    }

    dp[0][0] = true;
    for (int i = 1; i < N + 1; i++) {
        for (int j = cost_sum; j > -1; j--) {
            for (int k = cost_sum; k > -1; k--) {
                if (j - cost[i] >= 0) {
                    dp[j][k] |= dp[j - cost[i]][k];
                }
                if (k - cost[i] >= 0) {
                    dp[j][k] |= dp[j][k - cost[i]];
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < cost_sum + 1; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (dp[i][j] && (cost_sum - i - j) <= j) {
                answer = std::max(answer, cost_sum - i - j);
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}
