#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321

int N, M;
int S, T;
std::vector<std::pair<int, int>> edges[5001];
int dist[5001];

int main() {
    std::cin >> N >> M;

    for (int i = 1; i < N + 1; i++) {
        dist[i] = INF;
    }

    for (int i = 0; i < M; i++) {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        edges[from].push_back({to, cost});
        edges[to].push_back({from, cost});
    }

    std::cin >> S >> T;

    // S와 T가 연결된 상태
    std::priority_queue<std::pair<int, int>> pq;
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int current = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        for (auto p : edges[current]) {
            if (cost + p.second < dist[p.first]) {
                dist[p.first] = cost + p.second;
                pq.push({-(cost + p.second), p.first});
            }
        }
    }

//    for (int i = 1; i < N + 1; i++) {
//        std::cout << "dist[" << i << "]: " << dist[i] << "\n";
//    }

    std::cout << dist[T] << "\n";
    return 0;
}
