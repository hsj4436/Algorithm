#include <iostream>
#include <algorithm>
#include <vector>

int N;
bool visited[100001];
std::vector<int> graph[100001];
std::vector<int> inputOrder;
std::vector<int> generatedOrder;
int nodeOrder[100001];

void dfs(int cur) {
    for (int next : graph[cur]) {
        if (visited[next]) {
            continue;
        }
        visited[next] = true;
        generatedOrder.push_back(next);
        dfs(next);
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

    for (int i = 0; i < N; i++) {
        int v;
        std::cin >> v;
        inputOrder.push_back(v);
        nodeOrder[v] = i;
    }

    for (int i = 1; i < N + 1; i++) {
        std::sort(graph[i].begin(), graph[i].end(), [&](int a, int b) {
            return nodeOrder[a] < nodeOrder[b];
        });
    }

    visited[1] = true;
    generatedOrder.push_back(1);
    dfs(1);

    for (int i = 0; i < N; i++) {
        if (generatedOrder[i] != inputOrder[i]) {
            std::cout << "0\n";
            return 0;
        }
    }

    std::cout << "1\n";

    return 0;
}
