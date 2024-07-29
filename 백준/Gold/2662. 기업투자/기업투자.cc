#include <iostream>

int N, M;
int info[21][301];
int dp[21][301];
int from[21][301];

int main() {
    std::cin >> N >> M;

    std::fill_n(&info[0][0], 21 * 301, 0);

    int temp;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> temp;
        for (int j = 1; j < M + 1; j++) {
            std::cin >> info[j][i];
        }
    }

    for (int i = 1; i < M + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            for (int k = 0; k <= N - j; k++) {
                if (dp[i - 1][k] + info[i][j] > dp[i][k + j]) {
                    dp[i][k + j] = dp[i - 1][k] + info[i][j];
                    from[i][k + j] = j;
                }
            }
        }
    }

    int howMuch[21];
    int maxProfit = 0;
    std::pair<int, int> maxIndex;
    for (int i = 0; i < N + 1; i++) {
        if (dp[M][i] > maxProfit) {
            maxProfit = dp[M][i];
            maxIndex = {M, i};
        }
    }

    while (maxIndex.first != 0) {
        howMuch[maxIndex.first] = from[maxIndex.first][maxIndex.second];
        maxIndex = {maxIndex.first - 1, maxIndex.second - from[maxIndex.first][maxIndex.second]};
    }

    std::cout << maxProfit << "\n";
    for (int i = 1; i < M + 1; i++) {
        std::cout << howMuch[i] << " ";
    }

    return 0;
}
