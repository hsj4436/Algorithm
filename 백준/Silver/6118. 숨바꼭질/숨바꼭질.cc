#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
#define PII std::pair<int, int>

int N, M;
std::vector<int> graph[20001];
int dist[20001];

int main() {
    std::cin >> N >> M;

    std::fill(dist, dist + N + 1, INF);

    int A, B;
    for (int i = 0; i < M; i++) {
        std::cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    std::priority_queue<PII> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int d = -pq.top().first;
        pq.pop();

        for (int next : graph[cur]) {
            if (d + 1 < dist[next]) {
                dist[next] = d + 1;
                pq.push({-(d + 1), next});
            }
        }
    }

    int maxDistance = 0;
    int toHide = 0;
    int barns = 0;
    for (int i = 1; i < N + 1; i++) {
        if (dist[i] > maxDistance) {
            maxDistance = dist[i];
            toHide = i;
            barns = 1;
        } else if (dist[i] == maxDistance) {
            barns++;
        }
    }

    std::cout << toHide << " " << maxDistance << " " << barns << "\n";

    return 0;
}
