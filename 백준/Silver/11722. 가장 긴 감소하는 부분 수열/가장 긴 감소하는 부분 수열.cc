#include <iostream>

int N;
int arr[1001];
int dp[1001];

int main() {
    std::cin >> N;

    int answer = 0;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> arr[i];
        dp[i] = 1;
        int length = 0;
        for (int j = 1; j < i; j++) {
            if (arr[i] < arr[j] && dp[j] > length) {
                length = dp[j];
            }
        }
        dp[i] = length + 1;
        answer = std::max(answer, dp[i]);
    }

    std::cout << answer << "\n";

    return 0;
}
