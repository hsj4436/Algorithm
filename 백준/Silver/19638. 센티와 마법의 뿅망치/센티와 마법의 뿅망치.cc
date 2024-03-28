#include <iostream>
#include <queue>

int N, H, T;

int main() {
    std::cin >> N >> H >> T;

    int giant = 0;
    std::priority_queue<int> giants;
    for (int i = 0; i < N; i++) {
        std::cin >> giant;
        giants.push(giant);
    }

    if (giants.top() < H) {
        std::cout << "YES\n" << 0 << "\n";
        return 0;
    }

    for (int i = 1; i < T + 1; i++) {
        if (giants.top() == 1) {
            break;
        }
        int tallest = giants.top();
        giants.pop();
        giants.push(tallest / 2);
        if (giants.top() < H) {
            std::cout << "YES\n" << i << "\n";
            return 0;
        }
    }

    std::cout << "NO\n" << giants.top() << "\n";

    return 0;
}
