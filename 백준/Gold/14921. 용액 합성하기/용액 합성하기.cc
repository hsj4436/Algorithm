#include <iostream>

int N;
int L[100001];

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> L[i];
    }

    int diff = 987654321;
    int left = 0, right = N - 1;
    while (left < right) {
        int sum = L[left] + L[right];
        if (std::abs(sum) < std::abs(diff)) {
            diff = sum;
        }
        if (sum > 0) {
            right--;
        } else {
            left++;
        }
    }

    std::cout << diff << "\n";

    return 0;
}