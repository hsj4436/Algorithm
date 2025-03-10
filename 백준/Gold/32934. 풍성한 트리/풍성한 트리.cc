#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
std::vector<int> graph[200001];
bool isDegreeThree[200001];
std::vector<int> roots;

bool checkDegree() {
    for (int i = 1; i < N + 1; i++) {
        if (!(graph[i].size() == 1 || graph[i].size() == 3)) {
            return false;
        } else if (graph[i].size() == 3) {
            isDegreeThree[i] = true;
        }
    }

    return true;
}

int main() {
    std::cin >> N;

    int a, b;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (!checkDegree()) {
        std::cout << "-1\n";
        return 0;
    }

    bool visited[200001];
    for (int i = 1; i < N + 1; i++) {
        if (!isDegreeThree[i]) {
            continue;
        }
        std::fill_n(visited, 200001, false);
        std::queue<std::pair<int, int>> q;
        q.push({i, 0});
        visited[i] = true;

        int distance = -1;
        bool isRoot = true;
        while(!q.empty()) {
            int cur = q.front().first;
            int d = q.front().second;
            q.pop();

            bool isPossible = true;
            for (auto next : graph[cur]) {
                if (visited[next]) {
                    continue;
                }

                if (!isDegreeThree[next]) {
                    if (distance == -1) {
                        distance = d + 1;
                    } else if (d + 1 != distance) {
                        isPossible = false;
                        break;
                    }
                }

                visited[next] = true;
                q.push({next, d + 1});
            }
            if (!isPossible) {
                isRoot = false;
                break;
            }
        }
        if (isRoot) {
            roots.push_back(i);
        }
    }

    if (roots.empty()) {
        std::cout << "-1\n";
    } else {
        std::cout << roots.size() << "\n";
        for (auto i : roots) {
            std::cout << i << " ";
        }
    }

    return 0;
}
