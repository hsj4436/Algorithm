#include <iostream>

int N;
long long dp[1001][3][3][2]; // {index, from, current height, has 2}

long long sol(int index, int cur, int from, bool hasTwo) {
    if (index == N) {
        if (hasTwo) {
            return 1;
        } else {
            return 0;
        }
    }

    if (dp[index][from][cur][hasTwo] != 0) {
        return dp[index][from][cur][hasTwo];
    }

    if (cur == 0) {
        dp[index][from][cur][hasTwo] += sol(index + 1, 0, cur, hasTwo);
        dp[index][from][cur][hasTwo] += sol(index + 1, 1, cur, hasTwo);
        dp[index][from][cur][hasTwo] += sol(index + 1, 2, cur, true);
        dp[index][from][cur][hasTwo] %= 1000000007;
    } else if (cur == 1) {
        if (from == 0) {
            dp[index][from][cur][hasTwo] += sol(index + 1, 0, cur, hasTwo);
            dp[index][from][cur][hasTwo] += sol(index + 1, 1, cur, hasTwo);
            dp[index][from][cur][hasTwo] += sol(index + 1, 2, cur, true);
        } else {
            dp[index][from][cur][hasTwo] += sol(index + 1, 0, cur, hasTwo);
        }
        dp[index][from][cur][hasTwo] %= 1000000007;
    } else {
        if (from == 0) {
            dp[index][from][cur][hasTwo] += sol(index + 1, 0, cur, hasTwo);
            dp[index][from][cur][hasTwo] += sol(index + 1, 1, cur, hasTwo);
        } else {
            dp[index][from][cur][hasTwo] += sol(index + 1, 0, cur, hasTwo);
        }
        dp[index][from][cur][hasTwo] %= 1000000007;
    }

    return dp[index][from][cur][hasTwo];
}

int main() {
    std::cin >> N;

    std::cout << sol(1, 0, 0, false) << "\n";

    return 0;
}
