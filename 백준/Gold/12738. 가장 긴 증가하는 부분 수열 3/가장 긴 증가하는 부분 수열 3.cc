#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> LIS;

int main() {
    std::cin >> N;

    int num = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        if (LIS.empty() || LIS.back() < num) {
            LIS.push_back(num);
        } else {
            auto it = std::lower_bound(LIS.begin(), LIS.end(), num);
            *it = num;
        }
    }

    std::cout << LIS.size() << "\n";

    return 0;
}
