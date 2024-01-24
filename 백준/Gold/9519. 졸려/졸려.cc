#include <iostream>
#include <map>

int X;
std::string str;
std::map<int, std::string> x;

int main() {
    std::cin >> X >> str;

    std::string tmp = str;
    std::string ttmp(str.size(), ' ');
    int cnt = 0;
    x[0] = str;
    while (ttmp != str) {
        cnt++;
        if (str.size() % 2 == 0) {
            int left = 0, right = str.size() - 1;
            int idx = 0;
            while (idx < str.size()) {
                ttmp[left] = tmp[idx];
                ttmp[right] = tmp[idx + 1];
                idx += 2;
                left++;
                right--;
            }
        } else {
            int left = 0, right = str.size() - 1;
            int idx = 0;
            while (idx < str.size()) {
                ttmp[left] = tmp[idx];
                if (left == str.size() / 2) {
                    idx += 2;
                    continue;
                }
                ttmp[right] = tmp[idx + 1];
                idx += 2;
                left++;
                right--;
            }
        }
        tmp = ttmp;
        x[cnt] = ttmp;
        if (cnt == X) {
            std::cout << ttmp << "\n";
            return 0;
        }
    }

    X %= cnt;
    std::cout << x[X] << "\n";
    return 0;
}