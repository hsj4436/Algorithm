#include <iostream>
#include <vector>
#include <queue>

#define PII std::pair<int, int>

int N, Queries;
std::vector<PII> graph[5001];
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
        std::fill_n(&visited[0], 5001, false);
        std::queue<int> q;
        visited[V] = true;
        q.push(V);

        int answer = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (PII next : graph[cur]) {
                if (visited[next.first]) {
                    continue;
                }
                if (next.second < K) {
                    continue;
                }
                answer++;
                visited[next.first] = true;
                q.push(next.first);
            }
        }

        std::cout << answer << "\n";
    }

    return 0;
}
