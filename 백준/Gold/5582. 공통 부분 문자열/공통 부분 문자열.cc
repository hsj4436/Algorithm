#include <iostream>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    int dp[4001][4001];

    for (int i = 0; i < s.size(); i++) {
        dp[i][0] = s[i] == t[0] ? 1 : 0;
    }
    for (int i = 0; i < t.size(); i++) {
        dp[0][i] = s[0] == t[i] ? 1 : 0;
    }

    for (int i = 1; i < s.size(); i++) {
        for (int j = 1; j < t.size(); j++) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            answer = std::max(answer, dp[i][j]);
        }
    }
    std::cout << answer << "\n";
    return 0;
}
