#include <iostream>

int N;
std::string str;

int main() {
    std::cin >> N;
    std::cin >> str;

    int left = 0, right = N - 1;
    while (left <= right) {
        if (str[left] == '?' && str[right] == '?') {
            str[left] = 'a';
            str[right] = 'a';
        } else if (str[left] == '?') {
            str[left] = str[right];
        } else if (str[right] == '?') {
            str[right] = str[left];
        }
        left++;
        right--;
    }

    std::cout << str << "\n";

    return 0;
}
