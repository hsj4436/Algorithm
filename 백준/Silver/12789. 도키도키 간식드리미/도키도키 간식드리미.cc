#include <iostream>
#include <stack>

int N;
std::stack<int> line;
std::stack<int> space;

int main() {
    std::cin >> N;

    int num;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        space.push(num);
    }
    while (!space.empty()) {
        line.push(space.top());
        space.pop();
    }

    for (int i = 1; i < N + 1; i++) {
        if (!line.empty()) {
            if (line.top() == i) {
                line.pop();
            } else {
                if (!space.empty()) {
                    if (space.top() == i) {
                        space.pop();
                    } else {
                        while (!line.empty() && line.top() != i) {
                            space.push(line.top());
                            line.pop();
                        }
                        if (line.empty()) {
                            std::cout << "Sad\n";
                            return 0;
                        } else {
                            line.pop();
                        }
                    }
                } else {
                    while (!line.empty() && line.top() != i) {
                        space.push(line.top());
                        line.pop();
                    }
                    if (line.empty()) {
                        std::cout << "Sad\n";
                        return 0;
                    } else {
                        line.pop();
                    }
                }
            }
        } else {
            if (space.empty()) {
                std::cout << "Sad\n";
                return 0;
            } else {
                if (space.top() == i) {
                    space.pop();
                } else {
                    std::cout << "Sad\n";
                    return 0;
                }
            }
        }

    }
    std::cout << "Nice\n";
    return 0;
}
