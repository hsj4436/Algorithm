#include <iostream>

int main() {
    int left = 0, right = 0;
    while (true) {
        std::cin >> left >> right;
        if (left == 0 && right == 0) {
            break;
        }

        if (left > right) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}
