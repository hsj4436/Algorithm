#include <iostream>

int N;
int denominators[16];

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    std::cin >> N;

    long long numerator = 1, denominator = 1;
    for (int i = 0; i < N; i++) {
        std::cin >> denominators[i];
    }

    denominator = denominators[N - 1];
    numerator = 1;
    for (int i = N - 2; i > -1; i--) {
        long long temp_denominator = denominator;
        denominator = denominators[i] * denominator + numerator;
        numerator = temp_denominator;
    }

    numerator = denominator - numerator;
    long long divider = gcd(denominator, numerator);
    numerator /= divider;
    denominator /= divider;

    std::cout << numerator << " " << denominator << "\n";

    return 0;
}
