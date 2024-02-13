#include <iostream>

int N;
long long dp[31][31];

long long sol(int w, int h) {
    if (w == 0) {
        return 1;
    }

    if (dp[w][h] != -1) {
        return dp[w][h];
    }

    dp[w][h] = sol(w - 1, h + 1);

    if (h > 0) {
        dp[w][h] += sol(w, h - 1);
    }

    return dp[w][h];
}

int main() {

    while (true) {
        std::cin >> N;

        if (N == 0) {
            break;
        }

        std::fill(&dp[0][0], &dp[30][31], -1);
        std::cout << sol(N, 0) << "\n";
    }
    return 0;
}