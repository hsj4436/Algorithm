#include <iostream>
#include <algorithm>

int A, B, C;
int As[1001];
int Bs[1001];
int Cs[1001];

int main() {
    std::cin >> A >> B >> C;

    for (int i = 0; i < A; i++) {
        std::cin >> As[i];
        As[i] += 100000000;
    }
    for (int i = 0; i < B; i++) {
        std::cin >> Bs[i];
        Bs[i] += 100000000;
    }
    for (int i = 0; i < C; i++) {
        std::cin >> Cs[i];
        Cs[i] += 100000000;
    }

    std::sort(As, As + A);
    std::sort(Bs, Bs + B);
    std::sort(Cs, Cs + C);

    int answer = 200000001;

    for (int i = 0; i < A; i++) {
        auto j = std::lower_bound(Bs, Bs + B, As[i] - answer);
        for (; j < Bs + B; j++) {
            auto k = std::lower_bound(Cs, Cs + C, As[i] - answer);
            for (; k < Cs + C; k++) {
                int score = std::max(As[i], std::max(*j, *k)) - std::min(As[i], std::min(*j, *k));
                if (score > 2 * answer) {
                    break;
                }
                if (score < answer) {
                    answer = score;
                }
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}
