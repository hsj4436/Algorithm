#include <iostream>
#include <vector>
#include <queue>

#define INF 59999999
#define PII std::pair<int, int>

int N, M;
std::vector<PII> roads[50001];
int dist[50001];

int main() {
    std::cin >> N >> M;

    std::fill(dist + 1, dist + N + 1, INF);

    int A, B, C;
    for (int i = 0; i < M; i++) {
        std::cin >> A >> B >> C;
        roads[A].push_back({B, C});
        roads[B].push_back({A, C});
    }

    dist[1] = 0;
    std::priority_queue<PII> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int d = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (PII p : roads[cur]) {
            if (d + p.second < dist[p.first]) {
                dist[p.first] = d + p.second;
                pq.push({-(d + p.second), p.first});
            }
        }
    }

    std::cout << dist[N] << "\n";

    return 0;
}
