#include <iostream>
#include <algorithm>

std::string S, T;
bool possible = false;

void back_track(std::string str) {
    if (str == S) {
        possible = true;
        return;
    }

    if (str.back() == 'A') {
        std::string tmp = str;
        tmp.pop_back();
        back_track(tmp);
        if (possible) {
            return;
        }
    }

    if (str.back() == 'B') {
        std::string tmp = str;
        tmp.pop_back();
        std::reverse(tmp.begin(), tmp.end());
        back_track(tmp);
        if (possible) {
            return;
        }
    }
}

int main() {
    std::cin >> S >> T;

    back_track(T);

    if (possible) {
        std::cout << "1\n";
    } else {
        std::cout << "0\n";
    }

    return 0;
}
