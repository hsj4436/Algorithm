#include <iostream>

int main() {
    int sum = 0;
    int money = 0;
    while (true) {
        std::cin >> money;
        if (money == -1) {
            break;
        }
        sum += money;
    }
    
    std::cout << sum << "\n";
    
    return 0;
}
