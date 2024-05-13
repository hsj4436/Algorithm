#include <iostream>

#define LL long long

std::string input;
std::string numbers[35];
LL dp[35][40];

LL sol(int nIndex, int inputIndex) {
    if (inputIndex >= input.size()) {
        return 1;
    }

    if (dp[nIndex][inputIndex] != -1) {
        return dp[nIndex][inputIndex];
    }

    dp[nIndex][inputIndex] = 0;
    for (int i = 1; i < 35; i++) {
        std::string token = input.substr(inputIndex, numbers[i].size());
        if (token.size() != numbers[i].size()) {
            continue;
        }
        if (token == numbers[i]) {
            dp[nIndex][inputIndex] += sol(i, inputIndex + numbers[i].size());
        }
    }

    return dp[nIndex][inputIndex];
}

int main() {
    std::cin >> input;

    for (int i = 1; i < 35; i++) {
        numbers[i] = std::to_string(i);
    }

    std::fill_n(&dp[0][0], 35 * 40, -1);

    LL answer = 0;
    for (int i = 1; i < 35; i++) {
        std::string token = input.substr(0, numbers[i].size());
        if (token.size() != numbers[i].size()) {
            continue;
        }
        if (token == numbers[i]) {
            answer += sol(i, numbers[i].size());
        }
    }

    std::cout << answer << "\n";

    return 0;
}
