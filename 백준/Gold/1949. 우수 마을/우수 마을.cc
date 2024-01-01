#include <iostream>
#include <vector>

std::vector<int> edges[10001];
bool visited[10001] = {false, };

int population[10001] = {0, };
int dp[10001][2]; // 0 - normal, 1 - good

void dfs(int cur) {
    if (visited[cur]) {
        return;
    }

    visited[cur] = true;
    dp[cur][1] = population[cur];

    for (int i = 0; i < edges[cur].size(); i++) {
        if (visited[edges[cur][i]]) {
            continue;
        }

        dfs(edges[cur][i]);

        dp[cur][0] += std::max(dp[edges[cur][i]][1], dp[edges[cur][i]][0]);
        dp[cur][1] += dp[edges[cur][i]][0];
    }
}

int main() {

    int n = 0;
    std::cin >> n;

    for (int i = 1; i < n + 1; i++) {
        std::cin >> population[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u = 0, v = 0;
        std::cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(1);

    std::cout << std::max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}
