#include <iostream>
#include <vector>
#include <queue>

#define LL long long
#define PLL std::pair<long long, long long>

int N, M;
bool is_warded[100000];
std::vector<PLL> edge[100000];
LL dist[100000];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> is_warded[i];
        dist[i] = 20000000000;
    }
    is_warded[N - 1] = false;

    LL A, B, T;
    for (int i = 0; i < M; i++) {
        std::cin >> A >> B >> T;
        if (is_warded[A] || is_warded[B]) {
            continue;
        }
        edge[A].push_back({B, T});
        edge[B].push_back({A, T});
    }

    dist[0] = 0L;
    std::priority_queue<PLL> pq;
    pq.push({0L, 0L});

    while (!pq.empty()) {
        LL cur_cost = -pq.top().first;
        LL current = pq.top().second;
        pq.pop();

        if (cur_cost > dist[current]) {
            continue;
        }

        for (PLL p : edge[current]) {
            if (cur_cost + p.second < dist[p.first]) {
                dist[p.first] = cur_cost + p.second;
                pq.push({-(cur_cost + p.second), p.first});
            }
        }
    }

    if (dist[N - 1] == 20000000000) {
        std::cout << "-1\n";
    } else {
        std::cout << dist[N - 1] << "\n";
    }

    return 0;
}