#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> LIS;

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    int num;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> num;
        if (LIS.size() == 0 || LIS.back() < num) {
            LIS.push_back(num);
        } else {
            auto it = std::lower_bound(LIS.begin(), LIS.end(), num);
            *it = num;
        }
    }

    std::cout << LIS.size() << "\n";
    return 0;
}
