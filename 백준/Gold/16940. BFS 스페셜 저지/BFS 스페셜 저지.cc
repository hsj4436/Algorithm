#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int N;
std::vector<int> edges[100001];
std::vector<int> order;
bool visited[100001];

int main() {
    std::cin >> N;

    int x, y;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    int o;
    for (int i = 0; i < N; i++) {
        std::cin >> o;
        order.push_back(o);
        std::sort(edges[i + 1].begin(), edges[i + 1].end());
    }

    if (order[0] != 1) {
        std::cout << "0\n";
        return 0;
    }

    int orderIndex = 0;
    std::queue<std::vector<int>> q;
    q.push({1});
    visited[1] = true;

    while (!q.empty()) {
        std::vector<int> cur = q.front();
        q.pop();

        int start = orderIndex, end = orderIndex + cur.size();
        for (int i : cur) {
            if (!std::binary_search(cur.begin(), cur.end(), order[orderIndex])) {
                std::cout << "0\n";
                return 0;
            }
            orderIndex++;
        }

        for (int i = start; i < end; i++) {
            std::vector<int> nextV;
            for (int next : edges[order[i]]) {
                if (visited[next]) {
                    continue;
                }
                visited[next] = true;
                nextV.push_back(next);
            }
            q.push(nextV);
        }
    }

    std::cout << "1\n";

    return 0;
}
