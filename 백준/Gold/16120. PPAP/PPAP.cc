#include <iostream>
#include <vector>

int main() {
    std::string P;
    std::cin >> P;

    std::vector<char> v;
    bool isAAppeared = false;
    for (auto ch : P) {
        if (ch == 'P') {
            v.push_back(ch);
            if (isAAppeared) {
                for (int i = 0; i < 4; i++) {
                    if (v.empty()) {
                        std::cout << "NP\n";
                        return 0;
                    }
                    v.pop_back();
                }
                isAAppeared = false;
                v.push_back(ch);
            }
        } else {
            if (isAAppeared) {
                std::cout << "NP\n";
                return 0;
            }
            v.push_back(ch);
            isAAppeared = true;
        }
    }

    std::string remain = std::string(v.begin(), v.end());

    if (remain == "PPAP" || remain.empty() || remain == "P") {
        std::cout << "PPAP\n";
    } else {
        std::cout << "NP\n";
    }


    return 0;
}
