#include <iostream>
#include <vector>
#include <queue>

#define PII std::pair<int, int>

int N;
int costs[10001];
int finish_costs[10001];
int in_degree[10001];
std::vector<int> out_degree[10001];

int main() {
    std::cin >> N;

    int cost, pre_works, pre_work;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> cost >> pre_works;
        costs[i] = cost;
        in_degree[i] = pre_works;
        for (int j = 0; j < pre_works; j++) {
            std::cin >> pre_work;
            out_degree[pre_work].push_back(i);
        }
    }

    std::queue<int> q;
    for (int i = 1; i < N + 1; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            finish_costs[i] = costs[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : out_degree[cur]) {
            finish_costs[next] = std::max(finish_costs[next], finish_costs[cur] + costs[next]);
            in_degree[next]--;
            if (in_degree[next] == 0) {
                q.push(next);
            }
        }
    }

    int answer = 0;
    for (int i = 1; i < N + 1; i++) {
        answer = std::max(answer, finish_costs[i]);
    }
    std::cout << answer << "\n";

    return 0;
}