#include <iostream>
#include <vector>

int V, E;
std::vector<int> edges[10001];
int minArrival[10001];
bool isBreakPoint[10001];
int answer = 0;
int order = 1;

int dfs(int cur, bool isRoot) {
    minArrival[cur] = order;
    order++;
    int ret = minArrival[cur];
    int childs = 0;
    for (int next : edges[cur]) {
        if (minArrival[next] != 0) {
            ret = std::min(ret, minArrival[next]);
            continue;
        }
        childs++;
        int nextMinArrival = dfs(next, false);
        if (!isRoot && nextMinArrival >= minArrival[cur]) {
            isBreakPoint[cur] = true;
        }
        ret = std::min(ret, nextMinArrival);
    }

    if (isRoot && childs >= 2) {
        isBreakPoint[cur] = true;
    }

    return ret;
}

int main() {
    std::cin >> V >> E;

    int A, B;
    for (int i = 0; i < E; i++) {
        std::cin >> A >> B;
        edges[A].push_back(B);
        edges[B].push_back(A);
    }

    for (int i = 1; i < V + 1; i++) {
        if (minArrival[i] == 0) {
            dfs(i, true);
        }
    }

    for (int i = 1; i < V + 1; i++) {
        if (isBreakPoint[i]) {
            answer++;
        }
    }

    std::cout << answer << "\n";
    for (int i = 1; i < V + 1; i++) {
        if (isBreakPoint[i]) {
            std::cout << i << " ";
        }
    }

    return 0;
}
