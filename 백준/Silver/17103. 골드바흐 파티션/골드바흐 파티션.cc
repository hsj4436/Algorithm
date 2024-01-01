#include <iostream>

int T, N;
int primes[1000001];

int main() {
    for (int i = 2; i < 1000001; i++) {
        primes[i] = i;
    }
    for (int i = 2; i < 1000001; i++) {
        if (primes[i] == 0) {
            continue;
        }
        for (int j = i * 2; j < 1000001; j += i) {
            primes[j] = 0;
        }
    }

    std::cin >> T;

    for (int tc = 0; tc < T; tc++) {
        std::cin >> N;
        int answer = 0;
        for (int i = 2; i < N / 2 + 1; i++) {
            if (primes[i] == 0) {
                continue;
            }
            if (primes[N - i] != 0) {
                answer++;
            }
        }
        std::cout << answer << "\n";
    }
    return 0;
}
