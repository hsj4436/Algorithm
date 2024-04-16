#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1299710

int T;
bool isPrime[MAX];

int main() {
    std::cin >> T;

    std::fill(isPrime + 2, isPrime + MAX, true);

    for (int i = 2; i < MAX; i++) {
        if (!isPrime[i]) {
            continue;
        }
        for (int j = 2 * i; j < MAX; j += i) {
            isPrime[j] = false;
        }
    }

    std::vector<int> primes;
    std::vector<int> nonPrimes;
    for (int i = 0; i < MAX; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        } else {
            nonPrimes.push_back(i);
        }
    }

    int K;
    while (T--) {
        std::cin >> K;

        if (isPrime[K]) {
            std::cout << "0\n";
        } else {
            auto upperPrimeIterator = std::upper_bound(primes.begin(), primes.end(), K);
            int upperPrime = *upperPrimeIterator;
            int lowerPrime = 0;
            if (upperPrimeIterator == primes.begin()) {
                lowerPrime = -1;
            } else {
                lowerPrime = *(--upperPrimeIterator);
            }
            std::cout << std::upper_bound(nonPrimes.begin(), nonPrimes.end(), upperPrime) - std::upper_bound(nonPrimes.begin(), nonPrimes.end(), lowerPrime) + 1 << "\n";
        }
    }
    return 0;
}
