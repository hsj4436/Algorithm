#include <iostream>

int main() {
    int TC;
    std::cin >> TC;

    for (int i = 1; i < TC + 1; i++) {
        std::string first, second, third;
        std::cin >> first >> second >> third;

        bool dp[201][201];
        dp[0][0] = true;
        for (int j = 1; j < first.size() + 1; j++) {
            dp[j][0] = first[j - 1] == third[j - 1] ? dp[j -1][0] : false;
        }
        for (int j = 1; j < second.size() + 1; j++) {
            dp[0][j] = second[j - 1] == third[j - 1] ? dp[0][j - 1] : false;
        }
        for (int j = 1; j < first.size() + 1; j++) {
            for (int k = 1; k < second.size() + 1; k++) {
                char char_f = first[j - 1], char_s = second[k - 1], char_t = third[j + k - 1];
                if (char_f != char_t && char_s != char_t) {
                    dp[j][k] = false;
                } else if (char_f == char_t && char_s != char_t) {
                    dp[j][k] = dp[j - 1][k];
                } else if (char_f != char_t && char_s == char_t) {
                    dp[j][k] = dp[j][k - 1];
                } else {
                    dp[j][k] = dp[j][k - 1] || dp[j - 1][k];
                }
            }
        }

        if (dp[first.size()][second.size()]) {
            std::cout << "Data set " << i << ": yes\n";
        } else {
            std::cout << "Data set " << i << ": no\n";
        }
    }

    return 0;
}
