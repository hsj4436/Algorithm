#include <iostream>
#include <vector>

int N, M;
int cost[100001] = {0, };
bool visited[100001] = {false, };
std::vector<int> edges[100001];

void dfs(int cur, int w) {
    int next_cost = w;
    if (cost[cur] != 0) {
        next_cost += cost[cur];
    }
    cost[cur] += w;

    for (int next : edges[cur]) {
        if (visited[next]) {
            continue;
        }
        visited[next] = true;
        dfs(next, next_cost);
    }
}

int main() {
    std::cin >> N >> M;

    int supervisor;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> supervisor;
        if (i == 1) {
            continue;
        }
        edges[i].push_back(supervisor);
        edges[supervisor].push_back(i);
    }

    int who, w;
    for (int i = 0; i < M; i++) {
        std::cin >> who >> w;
        cost[who] += w;
    }

    visited[1] = true;
    dfs(1, 0);

    for (int i = 1; i < N + 1; i++) {
        std::cout << cost[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
