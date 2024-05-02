#include <iostream>
#include <vector>
#include <algorithm>

int TC;
int N;
std::string str;
std::vector<std::string> v;

void sol(int index) {
    if (index >= str.size()) {
        int answer = 0;
        char op = '/';
        int temp = 0;

        for (int i = 0; i < str.size(); i++) {
            if ('1' <= str[i] && str[i] <= '9') {
                temp *= 10;
                temp += str[i] - '0';
            } else if (str[i] == ' ') {

            } else {
                if (op == '+') {
                    answer += temp;
                } else if (op == '-') {
                    answer -= temp;
                } else {
                    answer += temp;
                }
                op = str[i];
                temp = 0;
            }
        }
        if (op == '+') {
            answer += temp;
        } else {
            answer -= temp;
        }

        if (answer == 0) {
            v.push_back(str);
        }
        return;
    }

    str.insert(index, "+");
    sol(index + 2);
    str[index] = '-';
    sol(index + 2);
    str[index] = ' ';
    sol(index + 2);
    str.erase(index, 1);
}

int main() {
    std::cin >> TC;

    while (TC--) {
        std::cin >> N;

        str.clear();
        for (int i = 1; i < N + 1; i++) {
            str.push_back(i + '0');
        }

        sol(1);

        std::sort(v.begin(), v.end());
        for (std::string s : v) {
            std::cout << s << "\n";
        }
        v.clear();

        std::cout << "\n";
    }
    return 0;
}
