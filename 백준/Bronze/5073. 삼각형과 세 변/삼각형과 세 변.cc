#include <iostream>
#include <algorithm>

int length[3];

int main() {
    while (true) {
        std::cin >> length[0] >> length[1] >> length[2];
        if (length[0] == 0 && length[1] == 0 && length[2] == 0) {
            return 0;
        }

        std::sort(length, length + 3);

        if (length[0] + length[1] <= length[2]) {
            std::cout << "Invalid\n";
            continue;
        }

        if (length[0] == length[1] && length[1] == length[2]) {
            std::cout << "Equilateral\n";
        } else if ((length[0] == length[1]) || (length[1] == length[2]) || (length[0] == length[2])) {
            std::cout << "Isosceles\n";
        } else {
            std::cout << "Scalene\n";
        }
    }
    return 0;
}
