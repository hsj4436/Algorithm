#include <iostream>
#include <vector>
#include <queue>

int N, M, K = 501;
std::vector<std::pair<int, int>> adj[300001];

int dijkstra(int start, int end) {
    int dist[300001];
    std::fill(dist, dist + 300001, 987654321);
    int visited[300001];
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        if (visited[cur]) {
            continue;
        }
        visited[cur] = 1;
        for (auto p : adj[cur]) {
            int next = p.first;
            int cost = p.second;
            if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;
                pq.push({dist[next], next});
            }
        }
    }

    return dist[end];
}

int main() {
    std::cin >> N >> M;

    std::string row;
    for (int i = 0; i < N; i++) {
        std::cin >> row;
        for (int j = 0; j < M; j++) {
            if (row[j] == '/') {
                adj[i * K + j].push_back({(i + 1) * K + (j + 1), 1});
                adj[(i + 1) * K + (j + 1)].push_back({i * K + j, 1});
                adj[(i + 1) * K + j].push_back({i * K + (j + 1), 0});
                adj[i * K + (j + 1)].push_back({(i + 1) * K + j, 0});
            } else {
                adj[i * K + j].push_back({(i + 1) * K + (j + 1), 0});
                adj[(i + 1) * K + (j + 1)].push_back({i * K + j, 0});
                adj[(i + 1) * K + j].push_back({i * K + (j + 1), 1});
                adj[i * K + (j + 1)].push_back({(i + 1) * K + j, 1});
            }
        }
    }

   int ans = dijkstra(0, N * K + M);

    if (ans == 987654321) {
        std::cout << "NO SOLUTION\n";
    } else {
        std::cout << ans << "\n";
    }
    return 0;
}
