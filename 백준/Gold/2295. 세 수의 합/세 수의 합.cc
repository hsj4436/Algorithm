#include <iostream>
#include <algorithm>

int N;
int U[1001];

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> U[i];
    }

    std::sort(U + 1, U + N + 1);

    for (int i = N; i > 0; i--) {
        bool found = false;
        int target = U[i];
        for (int j = i; j > 0; j--) {
            int right_end = U[j];
            int left = 1, right = j;
            while (left <= right) {
                int sum = right_end + U[left] + U[right];
                if (sum == target) {
                    found = true;
                    break;
                }
                if (sum > target) {
                    right--;
                } else {
                    left++;
                }
            }
            if (found) {
                std::cout << target << "\n";
                break;
            }
        }
        if (found) {
            break;
        }
    }
    return 0;
}
