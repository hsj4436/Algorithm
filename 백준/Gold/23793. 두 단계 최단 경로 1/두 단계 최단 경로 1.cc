#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000001
#define LL long long
#define PLL std::pair<LL, LL>

int N, M;
int U, V, W;
int X, Y, Z;
std::vector<PLL> graph[100001];
LL XZ[100001];
LL YZ[100001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        std::cin >> U >> V >> W;
        graph[U].push_back({V, W});
    }

    std::cin >> X >> Y >> Z;

    std::fill(XZ, XZ + 100001, INF);
    std::fill(YZ, YZ + 100001, INF);

    std::priority_queue<PLL> pq;
    XZ[X] = 0;
    pq.push({0, X});
    while (!pq.empty()) {
        LL cur = pq.top().second;
        LL dist = -pq.top().first;
        pq.pop();

        for (PLL next : graph[cur]) {
            if (dist + next.second < XZ[next.first]) {
                XZ[next.first] = dist + next.second;
                if (next.first == Y) {
                    continue;
                }
                pq.push({-(dist + next.second), next.first});
            }
        }
    }

    YZ[Y] = 0;
    pq.push({0, Y});
    while (!pq.empty()) {
        LL cur = pq.top().second;
        LL dist = -pq.top().first;
        pq.pop();

        for (PLL next : graph[cur]) {
            if (dist + next.second < YZ[next.first]) {
                YZ[next.first] = dist + next.second;
                pq.push({-(dist + next.second), next.first});
            }
        }
    }

    if (XZ[Y] == INF || YZ[Z] == INF) {
        std::cout << -1 << " ";
    } else {
        std::cout << XZ[Y] + YZ[Z] << " ";
    }

    if (XZ[Z] == INF) {
        std::cout << -1 << "\n";
    } else {
        std::cout << XZ[Z] << "\n";
    }

    return 0;
}