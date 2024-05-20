#include <iostream>
#include <algorithm>

int N;
int ages[300001];

int main() {
    std::cin >> N;

    for (int i = 0; i < 3 * N; i++) {
        std::cin >> ages[i];
    }

    std::sort(ages, ages + 3 * N);

    std::cout << ages[2 * N - 1] - ages[N] << "\n";

    return 0;
}
