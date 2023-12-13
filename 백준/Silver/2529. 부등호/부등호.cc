#include <iostream>

int k;
char op[10];
std::string str = "";
bool selected[10];

long long min_number = 9999999999;
long long max_number = 0;
std::string min_string;
std::string max_string;

void back_track(int index) {
    if (index == k + 1) {
        long long num = std::stoll(str);
        if (num < min_number) {
            min_number = num;
            min_string = str;
        }
        if (num > max_number) {
            max_number = num;
            max_string = str;
        }
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (selected[i]) {
            continue;
        }
        if (index == 0) {
            selected[i] = true;
            str.push_back(i + '0');
            back_track(index + 1);
            selected[i] = false;
            str.pop_back();
        } else {
            if (op[index - 1] == '<') {
                if (str.back() - '0' < i) {
                    selected[i] = true;
                    str.push_back(i + '0');
                    back_track(index + 1);
                    selected[i] = false;
                    str.pop_back();
                }
            } else {
                if (str.back() - '0' > i) {
                    selected[i] = true;
                    str.push_back(i + '0');
                    back_track(index + 1);
                    selected[i] = false;
                    str.pop_back();
                }
            }
        }
    }
}

int main() {
    std::cin >> k;

    for (int i = 0; i < k; i++) {
        std::cin >> op[i];
    }

    back_track(0);

    std::cout << max_string << "\n" << min_string << "\n";

    return 0;
}
