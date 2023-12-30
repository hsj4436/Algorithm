#include <iostream>
#include <tuple>

#define INF 987654321

int commands[100001];
int dp[100001][5][5];

int cost(int f1, int f2) {
    if (std::abs(f1 - f2) == 2) {
        return 4;
    } else if (f1 == f2) {
        return 1;
    }
    return 3;
}

int main() {
    int command = 0, index = 1;
    while (true) {
        std::cin >> command;
        if (command == 0) {
            break;
        }
        commands[index] = command;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                dp[index][i][j] = INF;
            }
        }
        index++;
    }

    dp[1][0][commands[1]] = 2;
    dp[1][commands[1]][0] = 2;
    for (int i = 2; i < index; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (j == 0 && k == 0) {
                    continue;
                }
                if (dp[i - 1][j][k] == INF) {
                    continue;
                }
                if (k == 0) {
                    dp[i][j][commands[i]] = std::min(dp[i][j][commands[i]], dp[i - 1][j][k] + 2);
                } else {
                    dp[i][j][commands[i]] = std::min(dp[i][j][commands[i]], dp[i - 1][j][k] + cost(k, commands[i]));
                }
                if (j == 0) {
                    dp[i][commands[i]][k] = std::min(dp[i][commands[i]][k], dp[i - 1][j][k] + 2);
                } else {
                    dp[i][commands[i]][k] = std::min(dp[i][commands[i]][k], dp[i - 1][j][k] + cost(j, commands[i]));
                }
            }
        }
    }

    int answer = INF;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            answer = std::min(answer, dp[index - 1][i][j]);
        }
    }
    std::cout << answer << "\n";

    return 0;
}
