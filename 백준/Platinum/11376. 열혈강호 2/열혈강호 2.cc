#include <iostream>
#include <cstring>
#include <vector>

int N, M;
bool visited[1001];
std::vector<int> jobs[1001];
int assigned_to[1001];

bool dfs(int worker) {
    visited[worker] = true;

    for (int job : jobs[worker]) {
        if (assigned_to[job] == 0 || (!visited[assigned_to[job]] && dfs(assigned_to[job]))) {
            assigned_to[job] = worker;
            return true;
        }
    }

    return false;
}

int main() {
    std::cin >> N >> M;

    int number_of_job, job;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> number_of_job;
        for (int j = 0; j < number_of_job; j++) {
            std::cin >> job;
            jobs[i].push_back(job);
        }
    }

    int answer = 0;
    for (int i = 1; i < N + 1; i++) {
        std::memset(visited, false, sizeof(visited));
        if (dfs(i)) {
            answer++;
        }
        std::memset(visited, false, sizeof(visited));
        if (dfs(i)) {
            answer++;
        }
    }

    std::cout << answer << "\n";

    return 0;
}
