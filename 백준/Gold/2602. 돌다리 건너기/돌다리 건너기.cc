#include <iostream>

std::string order;
std::pair<char, char> bridge[101];
int dp[101][2][21];

int main() {
    std::cin >> order;

    std::string row;
    std::cin >> row;
    for (int i = 0; i < row.size(); i++) {
        bridge[i].first = row[i];
        if (row[i] == order[0]) {
            dp[i][0][0] = 1;
        }
    }
    std::cin >> row;
    for (int i = 0; i < row.size(); i++) {
        bridge[i].second = row[i];
        if (row[i] == order[0]) {
            dp[i][1][0] = 1;
        }
    }

    for (int i = 0; i < row.size(); i++) {
        for (int j = 1; j < order.size(); j++) {
            if (bridge[i].first == order[j]) {
                for (int k = 0; k < i; k++) {
                    dp[i][0][j] += dp[k][1][j - 1];
                }
            }
            if (bridge[i].second == order[j]) {
                for (int k = 0; k < i; k++) {
                    dp[i][1][j] += dp[k][0][j - 1];
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < row.size(); i++) {
        answer += dp[i][0][order.size() - 1] + dp[i][1][order.size() - 1];
    }
    std::cout << answer << "\n";
    return 0;
}
