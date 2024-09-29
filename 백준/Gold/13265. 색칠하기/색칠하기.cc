#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

int T;
int N, M;
std::vector<int> edges[1001];
bool visited[1001];
int color[1001];

int main() {
    std::cin >> T;

    while (T--) {
        std::cin >> N >> M;

        int x, y;
        for (int i = 0; i < M; i++) {
            std::cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        bool possible = true;
        std::queue<int> q;
        for (int i = 1; i < N + 1; i++) {
            if (visited[i]) {
                continue;
            }
            color[i] = 1;
            visited[i] = true;
            q.push(i);

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (int next : edges[cur]) {
                    if (visited[next]) {
                        if (color[next] == color[cur]) {
                            possible = false;
                            break;
                        }
                        continue;
                    }
                    visited[next] = true;
                    if (color[cur] == 1) {
                        color[next] = 2;
                    } else {
                        color[next] = 1;
                    }
                    q.push(next);
                }
                if (!possible) {
                    break;
                }
            }
            if (!possible) {
                break;
            }
        }

        if (possible) {
            std::cout << "possible\n";
        } else {
            std::cout << "impossible\n";
        }

        std::fill_n(visited, 1001, false);
        std::fill_n(color, 1001, 0);

        for (int i = 1; i < 1001; i++) {
            edges[i].clear();
        }
    }
    return 0;
}
