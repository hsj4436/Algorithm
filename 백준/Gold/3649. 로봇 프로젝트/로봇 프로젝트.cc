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
        long long diff = -1;
        long long L1, L2;
        for (int i = 0; i < N - 1; i++) {
            int left = i + 1, right = N - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (lego[i] + lego[mid] < X) {
                    left = mid + 1;
                } else if (lego[i] + lego[mid] > X) {
                    right = mid - 1;
                } else {
                    found = true;
                    if (lego[mid] - lego[i] > diff) {
                        diff = lego[mid] - lego[i];
                        L1 = lego[i];
                        L2 = lego[mid];
                    }
                    break;
                }
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