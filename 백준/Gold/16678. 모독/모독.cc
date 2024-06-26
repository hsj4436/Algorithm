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
    if (honors[1] != 1) {
        hackers += honors[1] - 1;
        honors[1] = 1;
    }
    for (int i = 2; i < N + 1; i++) {
        if (honors[i] > honors[i - 1]) {
            hackers += honors[i] - (honors[i - 1] + 1);
            honors[i] = honors[i - 1] + 1;
        }
    }

    std::cout << hackers << "\n";

    return 0;
}
