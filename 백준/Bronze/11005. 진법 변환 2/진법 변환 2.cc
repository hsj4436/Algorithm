#include <iostream>

int N, B;

int main() {
    std::cin >> N >> B;

    std::string answer;
    while (N != 0) {
        char current = (N % B) + '0';
        if (B > 9 && current > '9') {
            current = current - '0' - 10 + 'A';
        }
        answer.push_back(current);
        N /= B;
    }

    for (auto it = answer.rbegin(); it != answer.rend(); it++) {
        std::cout << *it;
    }
    return 0;
}
