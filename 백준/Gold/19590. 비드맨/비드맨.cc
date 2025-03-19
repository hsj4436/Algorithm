#include <iostream>

int N;

int main() {
    std::cin >> N;

    int ball = 0;
    long long sum = 0;
    long long max = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> ball;
        sum += ball;
        max = std::max(max, (long long)ball);
    }

    if (max >= sum - max) {
        std::cout << max - (sum - max) << "\n";
    } else {
        std::cout << sum % 2 << "\n";
    }

    return 0;
}
