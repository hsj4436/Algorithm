#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

#define PII std::pair<int, int>

int N, T;
std::vector<int> xPoints[200001];
std::map<PII, bool> visited;

int main() {
    std::cin >> N >> T;

    int x, y;
    for (int i = 0; i < N; i++) {
        std::cin >> x >> y;
        xPoints[y].push_back(x);
    }

    for (int i = 0; i < T + 1; i++) {
        std::sort(xPoints[i].begin(), xPoints[i].end());
    }

    std::queue<std::pair<PII, int>> q;
    q.push({{0, 0}, 0});
    visited[{0, 0}] = true;

    int answer = -1;
    while (!q.empty()) {
        PII cur = q.front().first;
        int moved = q.front().second;
        q.pop();

        if (cur.second == T) {
            answer = moved;
            break;
        }

        for (int i = std::max(0, cur.second - 2); i < std::min(T + 1, cur.second + 3); i++) {
            auto it = std::lower_bound(xPoints[i].begin(), xPoints[i].end(), cur.first - 2);
            while (it != xPoints[i].end()) {
                if (*it - cur.first > 2) {
                    break;
                }
                if (!visited[{*it, i}]) {
                    visited[{*it, i}] = true;
                    q.push({{*it, i}, moved + 1});
                }
                it++;
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}
