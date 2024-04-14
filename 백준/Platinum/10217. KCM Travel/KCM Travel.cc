#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 1000001

int N, M, K;
std::vector<std::pair<int, std::pair<int, int>>> graph[101];
int dist[101][10001]; // dist[i][j] : 1부터 i번 도시까지 j비용으로 왔을 때 걸린 시간

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int T;
    std::cin >> T;

    std::cin >> N >> M >> K;

    int U, V, C, D;
    for (int i = 0; i < K; i++) {
        std::cin >> U >> V >> C >> D;
        graph[U].push_back({V, {C, D}});
    }

    for (int i = 2; i < N + 1; i++) {
        for (int j = 0; j < M + 1; j++) {
            dist[i][j] = INF;
        }
    }

    std::queue<std::pair<int, std::pair<int, int>>> q; // {time, {airport, cost}}
    q.push({0, {1, 0}});
    while (!q.empty()) {
        int t = -q.front().first;
        int cur = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        if (dist[cur][c] < t) {
            continue;
        }

        for (auto p : graph[cur]) {
            int next = p.first;
            int cost = p.second.first;
            int time = p.second.second;
            if (c + cost > M) {
                continue;
            }
            if (t + time < dist[next][c + cost]) {
                dist[next][c + cost] = t + time;
                for (int i = c + cost + 1; i < M + 1; i++) {
                    if (dist[next][i] < t + time) {
                        break;
                    }
                    dist[next][i] = t + time;
                }
                q.push({-(t + time), {next, c + cost}});
            }
        }
    }

    int answer = INF;
    for (int i = 0; i < M + 1; i++) {
        answer = std::min(answer, dist[N][i]);
    }
    if (answer == INF) {
        std::cout << "Poor KCM\n";
    } else {
        std::cout << answer << "\n";
    }

    return 0;
}
