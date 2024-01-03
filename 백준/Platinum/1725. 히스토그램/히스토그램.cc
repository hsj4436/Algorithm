#include <iostream>
#include <vector>
#include <tuple>
#include <stack>

int N;
int heights[100002];
std::stack<int> stk;

int main() {
    std::cin >> N;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> heights[i];
    }

    stk.push(0);
    int answer = 0;
    for (int i = 1; i < N + 2; i++) {
        while (!stk.empty() && heights[stk.top()] > heights[i]) {
            int check = stk.top();
            stk.pop();
            answer = std::max(answer, heights[check] * (i - stk.top() - 1));
        }
        stk.push(i);
    }

    std::cout << answer << "\n";

    return 0;
}