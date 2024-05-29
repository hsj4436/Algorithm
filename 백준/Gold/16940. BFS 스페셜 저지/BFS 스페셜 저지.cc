#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int N;
std::vector<int> edges[100001];
int order[100001];
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
    for (int i = 1; i < N + 1; i++) {
        std::cin >> o;
        order[o] = i;
    }

    for (int i = 1; i < N + 1; i++) {
        std::sort(edges[i].begin(), edges[i].end(), [&](int a, int b) {
            return order[a] < order[b];
        });
    }

    int orderSequence = 2;
    std::queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : edges[cur]) {
            if (visited[next]) {
                continue;
            }
            if (order[next] == orderSequence) {
                visited[next] = true;
                q.push(next);
                orderSequence++;
            } else {
                std::cout << "0\n";
                return 0;
            }
        }
    }

    std::cout << "1\n";

    return 0;
}
