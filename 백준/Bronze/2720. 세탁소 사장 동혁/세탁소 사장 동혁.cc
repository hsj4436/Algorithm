#include <iostream>

int T;

int main() {
    std::cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int C;
        std::cin >> C;
        int quarter = C / 25;
        C -= quarter * 25;
        int dime = C / 10;
        C -= dime * 10;
        int nickel = C / 5;
        C -= nickel * 5;
        int penny = C / 1;
        std::cout << quarter << " " << dime << " " << nickel << " " << penny << "\n";
    }
    return 0;
}
