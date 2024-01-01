#include <iostream>
#include <vector>

int N;
std::vector<int> stk;

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int command, num;
        std::cin >> command;
        if (command == 1) {
            std::cin >> num;
            stk.push_back(num);
        } else if (command == 2) {
            if (stk.empty()) {
                std::cout << "-1\n";
            } else {
                std::cout << stk.back() << "\n";
                stk.pop_back();
            }
        } else if (command == 3) {
            std::cout << stk.size() << "\n";
        } else if (command == 4) {
            if (stk.empty()) {
                std::cout << "1\n";
            } else {
                std::cout << "0\n";
            }
        } else {
            if (stk.empty()) {
                std::cout << "-1\n";
            } else {
                std::cout << stk.back() << "\n";
            }
        }
    }
    return 0;
}
