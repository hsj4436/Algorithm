#include <iostream>
#include <vector>
#include <algorithm>

int K, N;
std::vector<std::string> numbers;

int main() {
    std::cin >> K >> N;

    std::string number;
    for (int i = 0; i < K; i++) {
        std::cin >> number;
        numbers.push_back(number);
    }

    std::sort(numbers.begin(), numbers.end(), [&](std::string a, std::string b) {
        return std::stoi(a) > std::stoi(b);
    });

    for (int i = 0; i < N - K; i++) {
        numbers.push_back(numbers[0]);
    }

    std::sort(numbers.begin(), numbers.end(), [&](std::string a, std::string b) {
        return a + b > b + a;
    });
    
    if (N == K) {
        for (int i = 0; i < K; i++) {
            std::cout << numbers[i];
        }
        std::cout << "\n";
    } else {
        for (auto n : numbers) {
            std::cout << n;
        }
        std::cout << "\n";
    }

    return 0;
}
