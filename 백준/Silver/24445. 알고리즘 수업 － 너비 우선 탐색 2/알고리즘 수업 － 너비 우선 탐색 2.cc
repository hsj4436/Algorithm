#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int N, M, R;
bool visited[100001];
std::vector<int> edges[100001];
int orders[100001];

void bfs() {
    std::queue<int> trace;
    visited[R] = true;
    orders[R] = 1;
    trace.push(R);
    int order = 2;

    while (!trace.empty()) {
        int cur = trace.front();
        trace.pop();

        for (auto i : edges[cur]) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            orders[i] = order;
            order++;
            trace.push(i);
        }
    }
}

int main() {
    std::cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        int from, to;
        std::cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    for (int i = 1; i < N + 1; i++) {
        std::sort(edges[i].rbegin(), edges[i].rend());
    }

    bfs();

    for (int i = 1; i < N + 1; i++) {
        std::cout << orders[i] << "\n";
    }
    return 0;
}
