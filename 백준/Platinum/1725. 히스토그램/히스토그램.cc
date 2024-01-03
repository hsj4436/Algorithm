#include <iostream>
#include <vector>
#include <tuple>
#include <stack>

int N;
std::vector<std::tuple<int, int, int>> vec;
std::stack<std::pair<int, int>> stk;

int main() {
    std::cin >> N;

    int height = 0;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> height;
        if (height == 0) {
            while (!stk.empty()) {
                vec.push_back(std::make_tuple(stk.top().first, stk.top().second, i));
                stk.pop();
            }
            continue;
        }
        if (stk.empty()) {
            stk.push({height, i});
        } else {
            int start = 0;
            while (!stk.empty()) {
                if (stk.top().first <= height) {
                    break;
                } else {
                    vec.push_back(std::make_tuple(stk.top().first, stk.top().second, i));
                    start = stk.top().second;
                    stk.pop();
                }
            }
            if (start == 0) {
                stk.push({height, i});
            } else {
                stk.push({height, start});
            }
        }
    }

    while (!stk.empty()) {
        vec.push_back(std::make_tuple(stk.top().first, stk.top().second, N + 1));
        stk.pop();
    }

    int answer = 0;
    for (auto t : vec) {
        answer = std::max(answer, std::get<0>(t) * (std::get<2>(t) - std::get<1>(t)));
    }

    std::cout << answer << "\n";

    return 0;
}