#include <iostream>
#include <algorithm>

#define LL long long

LL D, P;
LL L, C;
LL dp[100001] = {0L, };

int main() {
    std::cin >> D >> P;

    dp[0] = 1;
    for (int i = 0; i < P; i++) {
        std::cin >> L >> C;

        for (LL j = D; j >= L; j--) {
            if (dp[j - L] != 0) {
                if (j == L) {
                    dp[j] = std::max(dp[j], C);
                } else {
                    dp[j] = std::max(dp[j], std::min(dp[j - L], C));
                }
            }
        }
    }

    std::cout << dp[D] << "\n";

    return 0;
}