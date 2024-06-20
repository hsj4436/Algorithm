#include <iostream>

int main() {
    std::string str1, str2, str3;
    std::cin >> str1 >> str2 >> str3;
    if ('0' <= str1[0] && str1[0] <= '9') {
        long long num = std::stoll(str1);
        num += 3;
        if (num % 3 == 0 && num % 5 == 0) {
            std::cout << "FizzBuzz\n";
        } else if (num % 3 == 0 && num % 5 != 0) {
            std::cout << "Fizz\n";
        } else if (num % 3 != 0 && num % 5 == 0) {
            std::cout << "Buzz\n";
        } else {
            std::cout << num << "\n";
        }
    } else if ('0' <= str2[0] && str2[0] <= '9') {
        long long num = std::stoll(str2);
        num += 2;
        if (num % 3 == 0 && num % 5 == 0) {
            std::cout << "FizzBuzz\n";
        } else if (num % 3 == 0 && num % 5 != 0) {
            std::cout << "Fizz\n";
        } else if (num % 3 != 0 && num % 5 == 0) {
            std::cout << "Buzz\n";
        } else {
            std::cout << num << "\n";
        }
    } else {
        long long num = std::stoll(str3);
        num += 1;
        if (num % 3 == 0 && num % 5 == 0) {
            std::cout << "FizzBuzz\n";
        } else if (num % 3 == 0 && num % 5 != 0) {
            std::cout << "Fizz\n";
        } else if (num % 3 != 0 && num % 5 == 0) {
            std::cout << "Buzz\n";
        } else {
            std::cout << num << "\n";
        }
    }
    return 0;
}
