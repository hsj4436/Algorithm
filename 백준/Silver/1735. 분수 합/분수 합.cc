#include <iostream>

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a % b);
    }
}

int main() {
    int a1, b1, a2, b2;
    std::cin >> a1 >> b1 >> a2 >> b2;
    
    int a = a1 * b2 + a2 * b1;
    int b = b1 * b2;
    int divider = GCD(a, b);
    std::cout << a / divider << " " << b / divider << "\n";
    return 0;
}