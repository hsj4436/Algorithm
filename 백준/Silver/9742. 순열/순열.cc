#include <iostream>
#include <algorithm>

int main() {
    std::string input;
    int order;
    while (std::cin >> input >> order) {
        if (std::cin.eof()) {
            break;
        }
        int cycle = 1;
        for (int i = 2; i < input.size() + 1; i++) {
            cycle *= i;
        }

        if (order > cycle) {
            std::cout << input << " " << order << " = No permutation\n";
            continue;
        }

        std::string inputCopy = input;
        int count = 1;
        do {
            if (count == order) {
                std::cout << input << " " << order << " = " << inputCopy << "\n";
                break;
            }
            count++;
        } while (std::next_permutation(inputCopy.begin(), inputCopy.end()));
    }
    return 0;
}
