#include <iostream>

#define LL long long

int number[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
std::string maxDp[101];
std::string minDp[101];
int TC;
int N;

int main() {
    std::cin >> TC;

    while (TC--) {
        std::cin >> N;

        std::fill_n(maxDp, 101, "");
        std::fill_n(minDp, 101, std::string(50, '9'));

        maxDp[0] = "", minDp[0] = "";
        for (LL i = 0; i < N + 1; i++) {
            for (LL j = 0; j < 10; j++) {
                if (i - number[j] >= 0) {
                    if (i == 6 && j == 0) {
                        continue;
                    }
                    if ((maxDp[i - number[j]] + std::to_string(j)).size() > maxDp[i].size()) {
                        maxDp[i] = maxDp[i - number[j]] + std::to_string(j);
                    } else if ((maxDp[i - number[j]] + std::to_string(j)).size() == maxDp[i].size() && maxDp[i - number[j]] + std::to_string(j) > maxDp[i]) {
                        maxDp[i] = maxDp[i - number[j]] + std::to_string(j);
                    }

                    if ((minDp[i - number[j]] + std::to_string(j)).size() < minDp[i].size()) {
                        minDp[i] = minDp[i - number[j]] + std::to_string(j);
                    } else if ((minDp[i - number[j]] + std::to_string(j)).size() == minDp[i].size() && minDp[i - number[j]] + std::to_string(j) < minDp[i]) {
                        minDp[i] = minDp[i - number[j]] + std::to_string(j);
                    }
                }
            }
        }

        std::cout << minDp[N] << " " << maxDp[N] << "\n";

    }

    return 0;
}
