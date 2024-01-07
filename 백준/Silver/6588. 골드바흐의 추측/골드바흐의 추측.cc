#include <iostream>

int N;
int primes[1000001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
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

    while (true) {
        std::cin >> N;
        if (N == 0) {
            break;
        }

        int a = 0, b = 0;
        for (int i = 3; i < N / 2 + 1; i++) {
            if (i % 2 == 0) {
                continue;
            }
            if (primes[i] != 0 && primes[N - i] != 0) {
                a = i;
                b = N - i;
                break;
            }
        }

        if (a != 0 && b != 0) {
            std::cout << N << " = " << a << " + " << b << "\n";
        } else {
            std::cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    return 0;
}
