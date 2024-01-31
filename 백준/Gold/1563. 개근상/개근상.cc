#include <iostream>

#define MOD 1000000

int N;
long long dp[1001][2][3]; // [i][j][k] - i일 일때 출석 상황이 j번 지각, k번 연속 결석

int main() {
    std::cin >> N;

    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    dp[1][1][0] = 1;
    for (int i = 2; i < N + 1; i++) {
        dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
        dp[i][0][1] = dp[i - 1][0][0] % MOD;
        dp[i][0][2] = dp[i - 1][0][1] % MOD;
        dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
        dp[i][1][1] = dp[i - 1][1][0] % MOD;
        dp[i][1][2] = dp[i - 1][1][1] % MOD;
    }

    std::cout << (dp[N][0][0] + dp[N][0][1] + dp[N][0][2] + dp[N][1][0] + dp[N][1][1] + dp[N][1][2]) % MOD << "\n";

    return 0;
}