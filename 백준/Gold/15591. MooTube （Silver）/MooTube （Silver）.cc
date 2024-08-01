#include <iostream>
#include <vector>
#include <queue>

#define PII std::pair<int, int>

int N, Queries;
std::vector<PII> graph[5001];
int USADO[5001];
bool visited[5001];

int main() {
    std::cin >> N >> Queries;

    int P, Q, R;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> P >> Q >> R;
        graph[P].push_back({Q, R});
        graph[Q].push_back({P, R});
    }

    int K, V;
    for (int i = 0; i < Queries; i++) {
        std::cin >> K >> V;
        std::fill_n(&USADO[0], 5001, 1000000001);
        std::fill_n(&visited[0], 5001, false);
        std::queue<PII> q;
        visited[V] = true;
        q.push({V, 1000000001});

        while (!q.empty()) {
            int cur = q.front().first;
            int u = q.front().second;
            q.pop();

            for (PII next : graph[cur]) {
                if (visited[next.first]) {
                    continue;
                }
                if (std::min(u, next.second) < USADO[next.first]) {
                    visited[next.first] = true;
                    USADO[next.first] = std::min(u, next.second);
                    q.push({next.first, std::min(u, next.second)});
                }
            }
        }

        int answer = 0;
        for (int j = 1; j < N + 1; j++) {
            if (j == V) {
                continue;
            }
            if (USADO[j] >= K) {
                answer++;
            }
        }
        std::cout << answer << "\n";
    }

    return 0;
}
