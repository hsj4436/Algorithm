#include <iostream>

int T;
int N, M, K;
int money[200001];

int main() {
    std::cin >> T;

    while (T--) {
        std::cin >> N >> M >> K;

        for (int i = 0; i < N; i++) {
            std::cin >> money[i];
        }
        for (int i = N; i < N + M - 1; i++) {
            money[i] = money[i % N];
        }

        int answer = 0;
        int sum = 0;
        for (int i = 0; i < M - 1; i++) {
            sum += money[i];
        }
        if (M == N) {
            sum += money[M - 1];
            if (sum < K) {
                answer++;
            }
            std::cout << answer << "\n";
            continue;
        }
        for (int i = M - 1; i < N + M - 1; i++) {
            sum -= money[i - M];
            sum += money[i];
            if (sum < K) {
                answer++;
            }
        }
        std::cout << answer << "\n";
    }
    return 0;
}
