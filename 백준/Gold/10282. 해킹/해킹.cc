#include <iostream>
#include <vector>
#include <queue>

std::vector<std::pair<int, int>> dependencies[10001];
int cost[10001];

void dijkstra(int start) {
    std::priority_queue<std::pair<int, int>> pq;
    cost[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_computer = pq.top().second;
        int current_cost = -pq.top().first;
        pq.pop();

        for (auto p : dependencies[current_computer]) {
            if (current_cost + p.second >= cost[p.first]) {
                continue;
            }

            cost[p.first] = current_cost + p.second;
            pq.push({-(current_cost + p.second), p.first});
        }
    }
}

int main() {
    int test_case = 0;
    std::cin >> test_case;

    for (int tc = 0; tc < test_case; tc++) {
        int n, d, c;
        std::cin >> n >> d >> c;

        std::fill(cost, cost + 10001, 10000001);
        for (int i = 1; i < n + 1; i++) {
            dependencies[i].clear();
        }

        for (int i = 0; i < d; i++) {
            int a, b, s;
            std::cin >> a >> b >> s;
            dependencies[b].push_back({a, s});
        }

        dijkstra(c);

        int total_cost = 0, total_computer = 0;
        for (int i = 1; i < n + 1; i++) {
            if (cost[i] < 10000001) {
                if (cost[i] > total_cost) {
                    total_cost = cost[i];
                }
                total_computer++;
            }
        }
        std::cout << total_computer << " " << total_cost << "\n";
    }
    return 0;
}
