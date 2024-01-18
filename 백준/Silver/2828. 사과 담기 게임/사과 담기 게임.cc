#include <iostream>

int N, M, J;

int main() {
    std::cin >> N >> M;
    int left = 1, right = M;
    std::cin >> J;

    int answer = 0;
    int apple;
    for (int i = 0; i < J; i++) {
        std::cin >> apple;
        if (apple >= left && apple <= right) {
            continue;
        }
        if (apple < left) {
            int distance = left - apple;
            answer += distance;
            right -= distance;
            left -= distance;
        } else {
            int distance = apple - right;
            answer += distance;
            right += distance;
            left += distance;
        }
    }

    std::cout << answer << "\n";
    
    return 0;
}
