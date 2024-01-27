#include <iostream>
#include <vector>
#include <cstring>

#define PII std::pair<int, int>

int TC;
int N, M;
int discovered[100001];
int scc = 0, vertex = 0;
int SCC[100001];
int SCC_in_degree[100001];
std::vector<int> stk;
std::vector<int> edges[100001];

int make_SCC(int cur) {
    int ret = discovered[cur] = vertex++;
    stk.push_back(cur);

    for (int next : edges[cur]) {
        if (discovered[next] == -1) {
            ret = std::min(ret, make_SCC(next));
        } else if (SCC[next] == -1) {
            ret = std::min(ret, discovered[next]);
        }
    }

    if (ret == discovered[cur]) {
        while (true) {
            int top = stk.back();
            stk.pop_back();
            SCC[top] = scc;
            if (top == cur) {
                break;
            }
        }
        scc++;
    }

    return ret;
}

int main() {
    std::cin >> TC;

    for (int tc = 0; tc < TC; tc++) {
        std::cin >> N >> M;

        for (int i = 1; i < N + 1; i++) {
            edges[i].clear();
        }
        vertex = scc = 0;
        std::fill(discovered, discovered + N + 1, -1);
        std::memset(SCC_in_degree, 0, sizeof(SCC_in_degree));
        std::fill(SCC, SCC + N + 1, -1);

        int x, y;
        for (int i = 0; i < M; i++) {
            std::cin >> x >> y;
            edges[x].push_back(y);
        }

        int cnt = 0;
        for (int i = 1; i < N + 1; i++) {
            if (discovered[i] == -1) {
                make_SCC(i);
            }
        }

        for (int i = 1; i < N + 1; i++) {
            for (int next : edges[i]) {
                if (SCC[next] == SCC[i]) {
                    continue;
                }
                SCC_in_degree[SCC[next]]++;
            }
        }

        for (int i = 0; i < scc; i++) {
            if (SCC_in_degree[i] == 0) {
                cnt++;
            }
        }

        std::cout << cnt << "\n";
    }

    return 0;
}