#include <iostream>
#include <limits.h>
#include <vector>

int N;
char exp[19];
bool bracket[19];
int answer = INT_MIN;

void sol(int index) {
    if (index >= N) {
        int result = exp[0] - '0';
        if (bracket[1]) {
            if (exp[1] == '+') {
                result = (exp[0] - '0') + (exp[2] - '0');
            } else if (exp[1] == '*') {
                result = (exp[0] - '0') * (exp[2] - '0');
            } else {
                result = (exp[0] - '0') - (exp[2] - '0');
            }
        }
        for (int i = bracket[1] ? 3 : 1; i < N;) {
            if (i + 2 < N && bracket[i + 2]) {
                int left = exp[i + 1] - '0';
                int right = exp[i + 3] - '0';
                int tmp = 0;
                if (exp[i + 2] == '+') {
                    tmp = left + right;
                } else if (exp[i + 2] == '*') {
                    tmp = left * right;
                } else {
                    tmp = left - right;
                }
                if (exp[i] == '+') {
                    result += tmp;
                } else if (exp[i] == '*') {
                    result *= tmp;
                } else {
                    result -= tmp;
                }
                i += 4;
            } else {
                int right = exp[i + 1] - '0';
                if (exp[i] == '+') {
                    result += right;
                } else if (exp[i] == '*') {
                    result *= right;
                } else {
                    result -= right;
                }
                i += 2;
            }
        }
        answer = std::max(answer, result);
        return;
    }

    bracket[index] = true;
    sol(index + 4);
    bracket[index] = false;
    sol(index + 2);
}

int main() {
    std::cin >> N;

    std::string expression;
    std::cin >> expression;
    for (int i = 0; i < N; i++) {
        exp[i] = expression[i];
    }

    sol(1);

    std::cout << answer << "\n";
    return 0;
}
