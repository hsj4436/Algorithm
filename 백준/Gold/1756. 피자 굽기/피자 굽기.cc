#include <iostream>
#include <vector>
#include <algorithm>

int D, N;
std::vector<int> diameters;

int binary_search(int target, int last_index) {
    int left = 0, right = last_index;
    while (left < right) {
        int mid = (left + right) / 2;
        if (diameters[mid] < target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left - 1;
}

int main() {
    std::cin >> D >> N;

    int diameter;
    std::cin >> diameter;
    diameters.push_back(diameter);

    for (int i = 1; i < D; i++) {
        std::cin >> diameter;
        diameters.push_back(std::min(diameter, diameters[i - 1]));
    }

    int last_depth = D;
    for (int i = 0; i < N; i++) {
        int pizza = 0;
        std::cin >> pizza;
        if (last_depth == -1) {
            continue;
        }
        int index = binary_search(pizza, last_depth);
        if (index < 0) {
            last_depth = -1;
        } else {
            last_depth = index;
        }
    }

    if (last_depth == -1) {
        std::cout << "0\n";
    } else {
        std::cout << last_depth + 1 << "\n";
    }

    return 0;
}
