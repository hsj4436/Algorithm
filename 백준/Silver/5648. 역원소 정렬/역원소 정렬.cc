#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

long long N = 0;
std::vector<long long> arr;

int main() {
    std::string line;
    std::string number;
    while (std::cin >> line) {
        std::istringstream iss(line);
        while (iss >> number) {
            if (N == 0) {
                N = std::stoll(number);
                continue;
            }
            std::reverse(number.begin(), number.end());
            arr.push_back(std::stoll(number));
        }
    }

    std::sort(arr.begin(), arr.end());

    for (long long i : arr) {
        std::cout << i << "\n";
    }

    return 0;
}
