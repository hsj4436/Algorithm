#include <iostream>
#include <vector>

struct shark {
    int size;
    int speed;
    int IQ;
    shark() {
        size = 0;
        speed = 0;
        IQ = 0;
    }
};

int N;
shark sharks[51];
std::vector<int> graph[101];
bool eaten[101];
int opponent[101];

bool dfs(int cur) {
    for (int i : graph[cur]) {
        if (eaten[i]) {
            continue;
        }
        eaten[i] = true;
        if (opponent[i] == 0 || dfs(opponent[i])) {
            opponent[i] = cur;
            return true;
        }
    }
    return false;
}

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> sharks[i].size >> sharks[i].speed >> sharks[i].IQ;
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (sharks[i].size == sharks[j].size && sharks[i].speed == sharks[j].speed && sharks[i].IQ == sharks[j].IQ) {
                if (i < j) {
                    graph[i].push_back(j + 50);
                }
            } else if (sharks[i].size >= sharks[j].size && sharks[i].speed >= sharks[j].speed && sharks[i].IQ >= sharks[j].IQ) {
                graph[i].push_back(j + 50);
            }
        }
    }

    for (int i = 1; i < N + 1; i++) {
        std::fill_n(eaten, 101, false);
        dfs(i);
        std::fill_n(eaten, 101, false);
        dfs(i);
    }

    int answer = 0;
    for (int i = 51; i < N + 1 + 50; i++) {
        if (opponent[i] == 0) {
            answer++;
        }
    }
    std::cout << answer << "\n";

    return 0;
}
