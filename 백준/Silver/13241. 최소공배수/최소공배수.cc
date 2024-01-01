#include <iostream>

long long GCD(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a % b);
    }
}

long long LCD(long long a, long long b) {
    return a * b / GCD(a, b);
}

int main() {
    long long A, B;
    std::cin >> A >> B;
    std::cout << LCD(A, B);
    return 0;
}