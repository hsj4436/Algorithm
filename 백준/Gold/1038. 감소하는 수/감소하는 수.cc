#include <iostream>

int N;
int cnt;
bool selected[10];

int back_track(int size, std::string number) {
    if (number.size() == size) {
        cnt++;
        if (cnt == N) {
            std::cout << number << "\n";
            return 1;
        }
        if (number == "9876543210") {
            return -1;
        }
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        if (number.size() == 0) {
            if (i == 0) {
                continue;
            }
            selected[i] = true;
            number.push_back(i + '0');
            int ret = back_track(size, number);
            if (ret != 0) {
                return ret;
            }
            number.pop_back();
            selected[i] = false;
        } else {
            if (i > number.back() - '0' || selected[i]) {
                continue;
            }
            selected[i] = true;
            number.push_back(i + '0');
            int ret = back_track(size, number);
            if (ret != 0) {
                return ret;
            }
            number.pop_back();
            selected[i] = false;
        }
    }

    return 0;
}

int main() {
    std::cin >> N;

    if (N == 0) {
        std::cout << "0\n";
        return 0;
    }

    for (int i = 1; i < 12; i++) {
        int ret = back_track(i, "");
        if (ret == 1) {
            return 0;
        } else if (ret == -1) {
            break;
        }
    }

    std::cout << "-1\n";

    return 0;
}
