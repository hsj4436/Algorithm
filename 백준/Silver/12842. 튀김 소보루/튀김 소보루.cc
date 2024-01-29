#include <iostream>

int N, S, M;
int T[100001];

int main() {
    std::cin >> N >> S >> M;

    for (int i = 1; i < M + 1; i++) {
        std::cin >> T[i];
    }

    if (N - S <= M) {
        std::cout << N - S << "\n";
        return 0;
    }

    int cnt = M, t = 1;
    while (true) {
        for (int i = 1; i < M + 1; i++) {
            if (t % T[i] == 0) {
                cnt++;
                if (cnt == N - S) {
                    std::cout << i << "\n";
                    return 0;
                }
            }
        }
        t++;
    }

    return 0;
}