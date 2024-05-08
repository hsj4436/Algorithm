#include <iostream>

int N;
int powers[100001];

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> powers[i];
    }

    int maxPower = 0;
    int left = 0, right= N - 1;
    while (left < right) {
        int curPower = std::min(powers[left], powers[right]) * (right - left - 1);
        maxPower = std::max(maxPower, curPower);

        if (powers[left] < powers[right]) {
            left++;
        } else {
            right--;
        }
    }

    std::cout << maxPower << "\n";

    return 0;
}
