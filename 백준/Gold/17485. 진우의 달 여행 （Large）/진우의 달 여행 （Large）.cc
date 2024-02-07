#include <iostream>

int N, M;
int arr[1001][1002];
int dp[1002][1002][3];

int main() {
    std::cin >> N >> M;

    std::fill(&dp[0][0][0], &dp[1001][1002][3], 1000000);
    std::fill(&arr[0][0], &arr[1000][1002], 1000000);

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            std::cin >> arr[i][j];
        }
    }

    for (int i = 1; i < M + 1; i++) {
        for (int j = 0; j < 3; j++) {
            dp[0][i][j] = 0;
            dp[1][i][j] = arr[1][i];
        }
    }

    for (int i = 2; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            for (int k = 0; k < 3; k++) {
                if (k == 0) {
                    for (int L = 0; L < 3; L++) {
                        if (k == L) {
                            continue;
                        }
                        dp[i][j][k] = std::min(dp[i - 1][j - 1][L] + arr[i][j], dp[i][j][k]);
                    }
                } else if (k == 1) {
                    for (int L = 0; L < 3; L++) {
                        if (k == L) {
                            continue;
                        }
                        dp[i][j][k] = std::min(dp[i - 1][j][L] + arr[i][j], dp[i][j][k]);
                    }
                } else {
                    for (int L = 0; L < 3; L++) {
                        if (k == L) {
                            continue;
                        }
                        dp[i][j][k] = std::min(dp[i - 1][j + 1][L] + arr[i][j], dp[i][j][k]);
                    }
                }
            }
        }
    }

    int ans = 1000000;
    for (int i = 1; i < M + 1; i++) {
        for (int j = 0; j < 3; j++) {
            ans = std::min(dp[N][i][j], ans);
        }
    }
    std::cout << ans << "\n";

    return 0;
}