#include <iostream>
#include <vector>
#include <cstring>

int N;
std::vector<std::pair<int, int>> coins;
int dp[50001];

int main() {
    for (int t = 0; t < 3; t++) {
        std::cin >> N;
        coins.clear();
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int a = 0, b = 0;
            std::cin >> a >> b;
            coins.push_back({a, b});
            sum += a * b;
        }
        std::memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        if (sum % 2 != 0) {
            std::cout << "0\n";
            continue;
        }

        for (int i = 0; i < N; i++) {
            for (int j = sum / 2; j >= coins[i].first; j--) {
                if (dp[j - coins[i].first] > 0) {
                    if (dp[j - coins[i].first] == 1) {
                        for (int k = 0; k < coins[i].second; k++) {
                            if (j + coins[i].first * k <= sum / 2) {
                                dp[j + coins[i].first * k] = 1;
                            }
                        }
                    }
                }
            }
        }

        std::cout << dp[sum / 2] << "\n";
    }

    return 0;
}
