#include <iostream>
#include <algorithm>

int N, C;
int weights[5001];

int main() {
    std::cin >> N >> C;

    for (int i = 0; i < N; i++) {
        std::cin >> weights[i];
        if (weights[i] == C) {
            std::cout << "1\n";
            return 0;
        }
    }
    
    std::sort(weights, weights + N);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (weights[i] + weights[j] == C) {
                std::cout << "1\n";
                return 0;
            }
            int left = j + 1, right = N - 1;
            int target = C - (weights[i] + weights[j]);
            if (target < 0) {
                continue;
            }
            while (left <= right) {
                int mid = (left + right) / 2;
                if (weights[mid] > target) {
                    right = mid - 1;
                } else if (weights[mid] < target) {
                    left = mid + 1;
                } else {
                    std::cout << "1\n";
                    return 0;
                }
            }
        }
    }

    std::cout << "0\n";

    return 0;
}
