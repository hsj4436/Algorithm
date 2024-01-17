#include <iostream>
#include <set>

int L, R, K;

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> L >> R >> K;

    int answer = 0;
    if (K == 2) {
        if (L > 3) {
            std::cout << R - L + 1 << "\n";
        } else {
            std::cout << R - 3 + 1 << "\n";
        }
        return 0;
    }
    if (K == 3) {
        for (int i = (L > 6 ? L : 6); i < R + 1; i++) {
            if (i % 3 == 0) {
                answer++;
            }
        }
    }
    if (K == 4) {
        for (int i = (L > 10 ? L : 10); i < R + 1; i++) {
            if (i == 12) {
                continue;
            }
            if (i % 2 == 0) {
                answer++;
            }
        }
    }
    if (K == 5) {
        for (int i = (L > 15 ? L : 15); i < R + 1; i++) {
            if (i % 5 == 0) {
                answer++;
            }
        }
    }
    std::cout << answer << "\n";

    return 0;
}
