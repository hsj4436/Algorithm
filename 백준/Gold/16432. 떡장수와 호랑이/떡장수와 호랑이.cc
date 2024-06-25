#include <iostream>
#include <vector>

int N;
bool riceCakes[1001][10];
bool continuable[1001][10];
std::vector<int> answer;

bool dfs(int day) {
    if (day == N + 1) {
        for (int i : answer) {
            std::cout << i << "\n";
        }
        return true;
    }

    if (day == 1) {
        for (int i = 1; i < 10; i++) {
            if (riceCakes[1][i]) {
                answer.push_back(i);
                if (dfs(day + 1)) {
                    return true;
                } else {
                    continuable[day][i] = false;
                    answer.pop_back();
                }
            }
        }
    } else {
        int from = answer.back();
        for (int i = 1; i < 10; i++) {
            if (riceCakes[day][i] && i != from && continuable[day][i]) {
                answer.push_back(i);
                if (dfs(day + 1)) {
                    return true;
                } else {
                    continuable[day][i] = false;
                    answer.pop_back();
                }
            }
        }
    }
    return false;
}

int main() {
    std::cin >> N;

    std::fill_n(&continuable[0][0], 1001 * 10, true);

    int m, a;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> m;
        for (int j = 0; j < m; j++) {
            std::cin >> a;
            riceCakes[i][a] = true;
        }
    }

    if (!dfs(1)) {
        std::cout << "-1\n";
    }

    return 0;
}
