#include <iostream>
#include <math.h>

int N;
std::pair<long long, long long> points[10001];

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> points[i].first >> points[i].second;
    }

    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += points[i].first * points[(i + 1) % N].second;
        sum -= points[i].second * points[(i + 1) % N].first;
    }

    sum *= 0.5;
    sum = std::abs(sum);
    sum = std::ceil(sum * 10.0) / 10.0;

    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << sum << "\n";
    return 0;
}
