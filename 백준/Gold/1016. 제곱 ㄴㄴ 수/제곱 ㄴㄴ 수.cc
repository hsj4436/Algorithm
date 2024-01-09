#include <iostream>
#include <math.h>
#include <vector>

long long min, max;
long long num[1000001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> min >> max;

    for (long long i = min; i < max + 1; i++) {
        num[i - min] = i;
    }

    for (long long i = 2; i * i < max + 1; i++) {
        long long n = min / (i * i);
        if (min % (i * i) != 0) {
            n++;
        }
        while (n * i * i <= max) {
            num[n * i * i - min] = 0;
            n++;
        }
    }

    long long answer = 0;
    for (long long i = min; i < max + 1; i++) {
        if (num[i - min] != 0) {
            answer++;
        }
    }

    std::cout << answer << "\n";

    return 0;
}
