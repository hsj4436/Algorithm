#include <iostream>
#include <queue>
#include <math.h>

int N;

int main() {
    std::cin >> N;

    if (N == 0) {
        std::cout << "0\n";
        return 0;
    }
    
    std::priority_queue<int> levels;
    for (int i = 0; i < N; i++) {
        int level = 0;
        std::cin >> level;
        levels.push(level);
    }

    int except = (int)std::round((double)N * 0.15);
    int include = N - 2 * except;
    int cnt = 0;
    while (cnt != except) {
        levels.pop();
        cnt++;
    }
    cnt = 0;
    int sum_of_level = 0;
    while (cnt != include) {
        sum_of_level += levels.top();
        levels.pop();
        cnt++;
    }

    std::cout << (int)std::round((double)sum_of_level / include) << "\n";
    return 0;
}
