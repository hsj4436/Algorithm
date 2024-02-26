#include <iostream>
#include <queue>
#include <vector>

int N;
std::vector<int> edges[3001];
bool is_cycle[3001];
int from[3001];
bool has_cycle = false;
bool visited[3001];
int min_dist[3001];

void dfs(int cur) {
    for (int next : edges[cur]) {
        if (has_cycle) {
            return;
        }
        if (visited[next]) {
            // 순환선 key
            if (next != from[cur]) {
                is_cycle[cur] = true;
                has_cycle = true;
                while (cur != next) {
                    is_cycle[from[cur]] = true;
                    cur = from[cur];
                }
                return;
            }
            continue;
        }
        visited[next] = true;
        from[next] = cur;
        dfs(next);
    }
}

int main() {
    std::cin >> N;

    int u, v;
    for (int i = 0; i < N; i++) {
        std::cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    visited[1] = true;
    from[1] = 1;
    dfs(1);

    std::fill(visited, visited + 3001, false);
    std::queue<std::pair<int, int>> q;
    for (int i = 1; i < N + 1; i++) {
        if (is_cycle[i]) {
            visited[i] = true;
            q.push({i, 0});
        }
    }
    while (!q.empty()) {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        for (int next : edges[cur]) {
            if (visited[next]) {
                continue;
            }
            visited[next] = true;
            min_dist[next] = dist + 1;
            q.push({next, dist + 1});
        }
    }

    for (int i = 1; i < N + 1; i++) {
        std::cout << min_dist[i] << " ";
    }

    return 0;
}