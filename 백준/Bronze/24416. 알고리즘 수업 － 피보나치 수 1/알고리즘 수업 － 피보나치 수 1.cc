#include <iostream>

int N;
int fibo[41];

int main() {
    std::cin >> N;

    fibo[1] = 1;
    fibo[2] = 1;
    for (int i = 3; i < N + 1; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    std::cout << fibo[N] << " " << N - 2 << "\n";

    return 0;
}
