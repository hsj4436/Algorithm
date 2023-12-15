#include <iostream>
#include <vector>
#include <queue>

int N, D;
std::vector<std::vector<int>> shortcuts[10001];
int distance[10001];

void dijkstra() {
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({0, 0}); // -distance, node

    while (!pq.empty()) {
        int cur = pq.top().second;
        int d = -pq.top().first;
        pq.pop();

        for (int i = cur; i < D + 1; i++) {
            for (auto v : shortcuts[i]) {
                if (distance[v[0]] > d + + (i - cur) + v[1]) {
                    distance[v[0]] = d + (i - cur) + v[1];
                    pq.push({-(d + (i - cur) + v[1]), v[0]});
                }
            }
        }
        distance[D] = std::min(distance[D], d + (D - cur));
    }
}

int main() {
    std::cin >> N >> D;

    std::fill(distance, distance + 10001, D);
    distance[0] = 0;
    for (int i = 0; i < N; i++) {
        int from = 0, to = 0, d = 0;
        std::cin >> from >> to >> d;

        if (to - from <= d) {
            continue;
        }

        if (to > D) {
            continue;
        }
        std::vector<int> v;
        v.push_back(to);
        v.push_back(d);
        shortcuts[from].push_back(v);
    }

    dijkstra();

    std::cout << distance[D] << "\n";

    return 0;
}
