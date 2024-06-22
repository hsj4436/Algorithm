#include <iostream>

#define INF 10100

int N, M;
bool jumpable[10001];
int dp[10001][151];

int main() {
    std::cin >> N >> M;

    std::fill_n(&jumpable[0], 10001, true);
    std::fill_n(&dp[0][0], 10001 * 151, INF);

    int smallRock;
    for (int i = 0; i < M; i++) {
        std::cin >> smallRock;
        jumpable[smallRock] = false;
    }

    if (jumpable[2]) {
        dp[2][1] = 1;
    }
    for (int i = 2; i < N; i++) {
        for (int j = 1; j < 151; j++) {
            if (dp[i][j] < INF) {
                int x = j;
                if (x - 1 > 0 && i + x - 1 <= N && jumpable[i + x - 1] && dp[i][j] + 1 < dp[i + x - 1][x - 1]) {
                    dp[i + x - 1][x - 1] = dp[i][j] + 1;
                }
                if (i + x <= N && jumpable[i + x] && dp[i][j] + 1 < dp[i + x][x]) {
                    dp[i + x][x] = dp[i][j] + 1;
                }
                if (x + 1 < 151 && i + x + 1 <= N && jumpable[i + x + 1] && dp[i][j] + 1 < dp[i + x + 1][x + 1]) {
                    dp[i + x + 1][x + 1] = dp[i][j] + 1;
                }
            }
        }
    }

    int answer = INF;
    for (int i = 1; i <= 150; i++) {
        answer = std::min(answer, dp[N][i]);
    }

    if (answer == INF) {
        std::cout << "-1\n";
    } else {
        std::cout << answer << "\n";
    }

    return 0;
}
