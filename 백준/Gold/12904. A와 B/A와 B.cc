#include <iostream>
#include <algorithm>

std::string S, T;

int main() {
    std::cin >> S >> T;

    while (true) {
        if (S.size() == T.size()) {
            if (S == T) {
                std::cout << "1\n";
            } else {
                std::cout << "0\n";
            }
            return 0;
        }
        
        if (T.back() == 'A') {
            T.pop_back();
        } else {
            T.pop_back();
            std::reverse(T.begin(), T.end());
        }
    }

    return 0;
}
