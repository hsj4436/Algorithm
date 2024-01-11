#include <iostream>

#define ULL unsigned long long

ULL primes[10000002];

int main() {
    for (ULL i = 2; i < 10000002; i++) {
        primes[i] = i;
    }

    for (ULL i = 2; i < 10000002; i++) {
        if (primes[i] == 0) {
            continue;
        }
        for (ULL j = i * 2; j < 10000002; j += i) {
            primes[j] = 0;
        }
    }

    ULL A, B;
    std::cin >> A >> B;

    ULL answer = 0;
    for (ULL i = 2; i * i <= B; i++) {
        if (primes[i] != 0) {
            ULL tmp = i;
            while (tmp <= B / i) {
                tmp *= i;
                if (A <= tmp) {
                    answer++;
                }
            }
        }
    }

    std::cout << answer << "\n";
    return 0;
}
