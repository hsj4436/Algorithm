#include <iostream>
#include <algorithm>

int N;
int honors[100001];

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> honors[i];
    }

    std::sort(honors + 1, honors + N + 1);

    long long hackers = 0;
    for (int i = 1, base = 1; i < N + 1; i++) {
        if (honors[i] < base) {
            continue;
        }
        hackers += honors[i] - base;
        base++;
    }

    std::cout << hackers << "\n";

    return 0;
}
