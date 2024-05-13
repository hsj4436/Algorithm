#include <iostream>

#define LL long long

std::string input;
std::string numbers[35];
LL dp[41];

LL sol(int index) {
    if (index == input.size()) {
        return 1;
    }

    if (dp[index] != -1) {
        return dp[index];
    }

    dp[index] = 0;

    if (input[index] == '0') {
        return 0;
    }

    if (index < input.size() - 1) {
        std::string token = input.substr(index, 2);
        if (std::stoi(token) < 35) {
            dp[index] += sol(index + 2);
            if (token[1] == '0') {
                return dp[index];
            }
        }
    }
    dp[index] += sol(index + 1);

    return dp[index];
}

int main() {
    std::cin >> input;

    for (int i = 1; i < 35; i++) {
        numbers[i] = std::to_string(i);
    }

    std::fill_n(&dp[0], 41, -1);

    LL answer = sol(0);

    std::cout << answer << "\n";

    return 0;
}
