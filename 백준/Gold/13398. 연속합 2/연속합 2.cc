#include <iostream>

int N;
int arr[100001];
int dp[100001][2];
int answer;

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> arr[i];
    }

    dp[1][0] = arr[1];
    dp[1][1] = arr[1];
    answer = arr[1];
    for (int i = 2; i < N + 1; i++) {
        dp[i][0] = std::max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        answer = std::max(dp[i][0], std::max(dp[i][1], answer));
    }

    std::cout << answer << "\n";

    return 0;
}
