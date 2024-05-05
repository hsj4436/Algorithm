#include <iostream>
#include <math.h>
#include <limits>
#include <queue>
#include <vector>

#define LL long long
#define PLL std::pair<LL, LL>

LL N, W;
double M;
PLL plants[1001];
double adj[1001][1001];
double dist[1001];

int main() {
    std::cin >> N >> W;

    std::cin >> M;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> plants[i].first >> plants[i].second;
        dist[i] = std::numeric_limits<double>::max();
        for (int j = 1; j < N + 1; j++) {
            adj[i][j] = std::numeric_limits<double>::max();
        }
    }

    LL left, right;
    for (int i = 0; i < W; i++) {
        std::cin >> left >> right;

        adj[left][right] = 0;
        adj[right][left] = 0;
    }

    std::priority_queue<std::pair<double, LL>> pq;
    dist[1] = 0.0;
    pq.push({0.0, 1});
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (adj[i][j] == 0) {
                continue;
            }
            double d = std::sqrt(std::pow(plants[i].first - plants[j].first, 2) + std::pow(plants[i].second - plants[j].second, 2));
            adj[i][j] = d;
            adj[j][i] = d;
        }
    }

    while (!pq.empty()) {
        double d = -pq.top().first;
        LL cur = pq.top().second;
        pq.pop();

        if (dist[cur] < d) {
            continue;
        }

        for (int i = 1; i < N + 1; i++) {
            if (i == cur) {
                continue;
            }
            double nextDistance = d + adj[cur][i];

            if (nextDistance < dist[i]) {
                dist[i] = nextDistance;
                pq.push({-nextDistance, i});
            }
        }
    }

    std::cout << (LL)(dist[N] * 1000.0) << "\n";

    return 0;
}
