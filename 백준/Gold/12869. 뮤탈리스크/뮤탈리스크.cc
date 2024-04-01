#include <iostream>
#include <vector>
#include <algorithm>

int N;
int firstHP = 0;
int secondHP = 0;
int thirdHP = 0;
int dp[61][61][61];
int damage[3] = {9, 3, 1};

int sol(int fHP, int sHP, int tHP) {
    if (fHP == 0 && sHP == 0 && tHP == 0) {
        return dp[0][0][0] = 0;
    }

    if (dp[fHP][sHP][tHP] != -1) {
        return dp[fHP][sHP][tHP];
    }
    dp[fHP][sHP][tHP] = 987654321;
    std::vector<int> comb;
    for (int i = 0; i < N; i++) {
        comb.push_back(i);
    }
    do {
        int nfHP = fHP, nsHP = sHP, ntHP = tHP;
        if (N >= 1) {
            nfHP = (nfHP - damage[comb[0]] <= 0) ? 0 : nfHP - damage[comb[0]];
        }
        if (N >= 2) {
            nsHP = (nsHP - damage[comb[1]] <= 0) ? 0 : nsHP - damage[comb[1]];
        }
        if (N == 3) {
            ntHP = (ntHP - damage[comb[2]] <= 0) ? 0 : ntHP - damage[comb[2]];
        }

        dp[fHP][sHP][tHP] = std::min(dp[fHP][sHP][tHP], sol(nfHP, nsHP, ntHP) + 1);
    } while (std::next_permutation(comb.begin(), comb.end()));

    return dp[fHP][sHP][tHP];
}

int main() {
    std::cin >> N;

    if (N >= 1) {
        std::cin >> firstHP;
    }
    if (N >= 2) {
        std::cin >> secondHP;
    }
    if (N == 3) {
        std::cin >> thirdHP;
    }

    for (int i = 0; i < 61; i++) {
        for (int j = 0; j < 61; j++) {
            for (int k = 0; k < 61; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    std::cout << sol(firstHP, secondHP, thirdHP) << "\n";

    return 0;
}
