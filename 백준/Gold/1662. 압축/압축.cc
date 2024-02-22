#include <iostream>
#include <stack>

#define PCI std::pair<char, int>

std::string input;

int main() {
    std::cin >> input;

    std::stack<PCI> stk;

    for (int i = 0; i < input.size(); i++) {
        if ('0' <= input[i] && input[i] <= '9') {
            stk.push({input[i], 1});
        } else if (input[i] == '(') {
            stk.push({input[i], -1});
        } else if (input[i] == ')') {
            PCI Q;
            if (stk.top().first == '(') {
                Q = {' ', 0};
            } else {
                Q = stk.top();
                stk.pop();
            }
            while (stk.top().first != '(') {
                Q.second += stk.top().second;
                stk.pop();
            }
            stk.pop();
            PCI K = stk.top();
            stk.pop();
            PCI next = {Q.first, Q.second * (K.first - '0')};
            if (!stk.empty()) {
                if (stk.top().first == '(') {
                    stk.push(next);
                    continue;
                }
                while (!stk.empty()) {
                    if (stk.top().first == '(') {
                        break;
                    }
                    next.second += stk.top().second;
                    stk.pop();
                }
                stk.push(next);
            } else {
                stk.push(next);
            }
        }
    }

    int length = 0;
    while (!stk.empty()) {
        length += stk.top().second;
        stk.pop();
    }

    std::cout << length << "\n";

    return 0;
}
