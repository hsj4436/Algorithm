#include <iostream>
#include <stack>

int N;

int main() {
    std::cin >> N;

    long long answer = 0;
    std::stack<std::pair<int, int>> s;
    int current = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> current;

        int same_height = 1;
        while (!s.empty() && s.top().first < current) {
            answer += s.top().second;
            s.pop();
        }

        if (!s.empty()) {
            if (s.top().first == current) {
                answer += s.top().second;
                same_height = s.top().second + 1;
                if (s.size() > 1) {
                    answer++;
                }
                s.pop();
            } else {
                answer++;
            }
        }
        s.push({current, same_height});
    }


    std::cout << answer << "\n";
    return 0;
}
