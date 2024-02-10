#include <iostream>

int N;
int arr[5001];
int dp[5001][5001];

int sol(int left, int right) {
    if (left >= right) {
        return 0;
    }

    if (dp[left][right] != -1) {
        return dp[left][right];
    }

    if (arr[left] == arr[right]) {
        return dp[left][right] = sol(left + 1, right - 1);
    } else {
        int t1 = 1 + sol(left + 1, right);
        int t2 = 1 + sol(left, right - 1);
        return dp[left][right] = std::min(t1, t2);
    }
}

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> arr[i];
    }

    std::fill(&dp[0][0], &dp[5000][5001], -1);

    std::cout << sol(1, N) << "\n";

    return 0;
}