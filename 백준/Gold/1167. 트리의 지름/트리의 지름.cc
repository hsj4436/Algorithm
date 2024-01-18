#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> edges[100001];
bool visited[100001] = {false, };

int max_dist = 0;
int max_vertex = 0;

void dfs(int start, int dist) {
    visited[start] = true;

    if (dist > max_dist) {
        max_dist = dist;
        max_vertex = start;
    }

    for (std::pair<int, int> info : edges[start]) {
        if (visited[info.first]) {
            continue;
        }

        dfs(info.first, dist + info.second);
    }
}

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int v = 0;
    std::cin >> v;

    for (int i = 0; i < v; i++) {
        int start = 0;
        std::cin >> start;
        int dest = 0, dist = 0;
        while (1) {
            std::cin >> dest;
            if (dest == -1) {
                break;
            }
            std::cin >> dist;
            edges[start].push_back({dest, dist});
        }
    }

    dfs(1, 0);

    for (int i = 1; i < v + 1; i++) {
        visited[i] = false;
    }

    dfs(max_vertex, 0);

    std::cout << max_dist << "\n";

    return 0;
}
