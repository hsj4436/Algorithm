#include <iostream>
#include <vector>
#include <cstring>

int N, M;
std::vector<int> graph[1001];
bool visited[1001];
int assigned_worker[1001];

bool dfs(int worker) {
    for (int job : graph[worker]) {
        if (visited[job]) {
            continue;
        }
        visited[job] = true;
        if (assigned_worker[job] == 0 || dfs(assigned_worker[job])) {
            assigned_worker[job] = worker;
            return true;
        }
    }

    return false;
}

int main() {
    std::cin >> N >> M;

    int m, job;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> m;
        for (int j = 0; j < m; j++) {
            std::cin >> job;
            graph[i].push_back(job);
        }
    }

    int answer = 0;
    for (int i = 1; i < N + 1; i++) {
        std::memset(visited, false, sizeof(visited));
        if (dfs(i)) {
            answer++;
        }
    }

    std::cout << answer << "\n";

    return 0;
}