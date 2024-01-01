#include <iostream>

int main() {
    long long N;
    std::cin >> N;

    int answer = 0;
    for (long long i = 1; i * i <= N; i++) {
        answer++;
    }

    std::cout << answer << "\n";
    return 0;
}
