#include <iostream>
#include <algorithm>
#include <vector>

int N;
bool visited[100001];
std::vector<int> graph[100001];
std::vector<int> inputOrder;
int orderIndex = 0;
bool isEnd = false;

void dfs(int cur) {
    bool isLeaf = true;
    for (int next : graph[cur]) {
        if (!visited[next]) {
            isLeaf = false;
            break;
        }
    }
    if (isLeaf) {
        return;
    }
    auto next = std::find(graph[cur].begin(), graph[cur].end(), inputOrder[orderIndex]);
    if (next == graph[cur].end()) {
        isEnd = true;
        return;
    }
    while (next != graph[cur].end()) {
        int index = next - graph[cur].begin();
        if (visited[graph[cur][index]]) {
            isEnd = true;
            return;
        }
        visited[graph[cur][index]] = true;
        orderIndex++;
        dfs(graph[cur][index]);
        if (isEnd) {
            return;
        }
        next = std::find(graph[cur].begin(), graph[cur].end(), inputOrder[orderIndex]);
    }
}


int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int A, B;
        std::cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    for (int i = 1; i < N + 1; i++) {
        int v;
        std::cin >> v;
        inputOrder.push_back(v);
        std::sort(graph[i].begin(), graph[i].end());
    }

    if (inputOrder[0] != 1) {
        std::cout << "0\n";
        return 0;
    }

    visited[1] = true;
    orderIndex++;
    dfs(1);

    if (orderIndex == N) {
        std::cout << "1\n";
    } else {
        std::cout << "0\n";
    }


    return 0;
}
