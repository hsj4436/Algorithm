#include <iostream>
#include <algorithm>
#include <cstring>

#define PII std::pair<int, int>

long long X, N;
long long lego[1000001];

int main() {
    while (std::cin >> X) {
        std::cin >> N;
        X *= 10000000;
        std::memset(lego, 0, sizeof(lego));
        for (int i = 0; i < N; i++) {
            std::cin >> lego[i];
        }

        std::sort(lego, lego + N);

        bool found = false;
        long long L1, L2;
        int left = 0, right = N - 1;
        while (left < right) {
            long long sum = lego[left] + lego[right];
            if (sum < X) {
                left++;
            } else if (sum > X) {
                right--;
            } else {
                found = true;
                L1 = lego[left];
                L2 = lego[right];
                break;
            }
        }
        if (found) {
            std::cout << "yes " << L1 << " " << L2 << "\n";
        } else {
            std::cout << "danger\n";
        }
    }

    return 0;
}