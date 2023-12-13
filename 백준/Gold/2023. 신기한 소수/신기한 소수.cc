#include <iostream>
#include <cmath>

int N;

bool is_prime(int x) {
    if (x == 1) {
        return false;
    }
    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void back_track(std::string str) {
    for (int i = 1; i < 10; i++) {
        str.push_back(i + '0');
        int num = std::stoi(str);

        if (is_prime(num)) {
            if (str.size() == N) {
                std::cout << str << "\n";
            } else {
                back_track(str);
            }
        }

        str.pop_back();
    }
}

int main() {
    std::cin >> N;

    back_track("");

    return 0;
}
