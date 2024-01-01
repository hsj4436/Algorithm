#include <iostream>
#include <vector>

std::vector<int> dividers;

int main() {
    int n;
    while (true) {
        std::cin >> n;
        
        if (n == -1) {
            break;
        }
        dividers.clear();
        int sum = 0;
        for (int i = 1; i < n / 2 + 1; i++) {
            if (n % i == 0) {
                sum += i;
                dividers.push_back(i);
            }
        }
        
        if (sum == n) {
            std::cout << n << " = ";
            for (int i = 0; i <dividers.size(); i++) {
                if (i == dividers.size() - 1) {
                    std::cout << dividers[i] << "\n";
                } else {
                    std::cout << dividers[i] << " + ";
                }
            }
        } else {
            std::cout << n << " is NOT perfect.\n";
        }
    }
    return 0;
}