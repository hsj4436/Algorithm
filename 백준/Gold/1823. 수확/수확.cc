#include <iostream>

int N;
int cost[2001];
int dp[2001][2001];

int sol(int left, int right, int count) {
    if (left == right) {
        if (count == N) {
            return dp[left][right] = cost[left] * count;
        } else {
            return 0;
        }
    }

    if (dp[left][right] != 0) {
        return dp[left][right];
    }

    int left_select = sol(left + 1, right, count + 1) + cost[left] * count;
    int right_select = sol(left, right - 1, count + 1) + cost[right] * count;
    if (left_select > right_select) {
        dp[left][right] = left_select;
    } else {
        dp[left][right] = right_select;
    }

    return dp[left][right];
}

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> cost[i];
    }

    std::cout << sol(1, N, 1);

    return 0;
}