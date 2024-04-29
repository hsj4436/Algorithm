#include <iostream>

int N, K;
int section[101][4]; // [time when walk, profit when walk, time when bicycle, profit when bicycle]
int dp[101][100001];

int main() {
    std::cin >> N >> K;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> section[i][0] >> section[i][1] >> section[i][2] >> section[i][3];
    }

    std::fill(&dp[0][0], &dp[100][100001], -1);
    for (int i = 0; i < K + 1; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < K + 1; j++) {
            if (j - section[i][0] >= 0 && dp[i - 1][j - section[i][0]] >= 0) {
                dp[i][j] = dp[i - 1][j - section[i][0]] + section[i][1];
            }
            if (j - section[i][2] >= 0 && dp[i - 1][j - section[i][2]] >= 0) {
                dp[i][j] = std::max(dp[i - 1][j - section[i][2]] + section[i][3], dp[i][j]);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < K + 1; i++) {
        answer = std::max(answer, dp[N][i]);
    }
    std::cout << answer << "\n";

    return 0;
}
