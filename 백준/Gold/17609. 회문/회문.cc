#include <iostream>

int T;
std::string str;

int main() {
    std::cin >> T;

    while (T--) {
        std::cin >> str;

        int left = 0, right = str.size() - 1;
        bool erased = false;
        bool isPalindrome = true;
        while (left <= right) {
            if (str[left] == str[right]) {
                left++;
                right--;
            } else if (!erased) {
                if (left + 1 < right && str[left + 1] == str[right]) {
                    erased = true;
                    left += 2;
                    right--;
                    continue;
                }
                if (left + 1 == right) {
                    erased = true;
                    break;
                } else {
                    isPalindrome = false;
                    break;
                }
            } else {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome) {
            if (erased) {
                std::cout << "1\n";
            } else {
                std::cout << "0\n";
            }
            continue;
        }

        left = 0, right = str.size() - 1;
        erased = false;
        isPalindrome = true;
        while (left <= right) {
            if (str[left] == str[right]) {
                left++;
                right--;
            } else if (!erased) {
                if (right - 1 > left && str[left] == str[right - 1]) {
                    erased = true;
                    left++;
                    right -= 2;
                    continue;
                }
                if (left + 1 == right) {
                    erased = true;
                    break;
                } else {
                    isPalindrome = false;
                    break;
                }
            } else {
                isPalindrome = false;
                break;
            }
        }

        if (!isPalindrome) {
            std::cout << "2\n";
        } else {
            if (erased) {
                std::cout << "1\n";
            } else {
                std::cout << "0\n";
            }
        }
    }
    return 0;
}
