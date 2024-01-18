#include <iostream>
#include <queue>
#include <cstring>

int TC, N;
bool visited[20001];
int remain[2];
std::string num[2];

void bfs() {
    std::queue<std::pair<int, std::string>> q;
    q.push({1,"1"});
    visited[1] = true;

    while (!q.empty()) {
        int x = q.front().first;
        std::string cur = q.front().second;
        q.pop();

        if (x == 0) {
            std::cout << cur << "\n";
            return;
        }

        remain[0] = (x * 10) % N;
        num[0] = cur + "0";

        remain[1] = (x * 10 + 1) % N;
        num[1] = cur + "1";

        for (int i = 0; i < 2; i++) {
            if (visited[remain[i]]) {
                continue;
            }
            visited[remain[i]] = true;
            q.push({remain[i], num[i]});
        }
    }
    std::cout << "BRAK\n";
}

int main() {
    std::cin >> TC;

    for (int tc = 0; tc < TC; tc++) {
        std::cin >> N;
        std::memset(visited, false, sizeof(visited));
        if (N == 1) {
            std::cout << "1\n";
        } else {
            bfs();
        }
    }
    return 0;
}
