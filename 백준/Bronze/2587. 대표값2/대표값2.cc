#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers(5);
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        std::cin >> numbers[i];
        sum += numbers[i];
    }
    
    std::sort(numbers.begin(), numbers.end());
    
    std::cout << sum / 5 << "\n" << numbers[2] << "\n";
    
    return 0;
}