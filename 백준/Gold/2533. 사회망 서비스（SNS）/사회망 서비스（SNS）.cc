#include <iostream>
#include <vector>

// 27
std::vector<int> edges[1000001];
bool visited[1000001] = {false, };
int dp[1000001][2]; // 0 - non_early_adapter, 1 - early_adapter

void dfs(int cur) {
    if (visited[cur]) {
        return;
    }

    visited[cur] = true;

    dp[cur][0] = 0;
    dp[cur][1] = 1;

    for (int i = 0; i < edges[cur].size(); i++) {
        if (visited[edges[cur][i]]) {
            continue;
        }

        dfs(edges[cur][i]);

        dp[cur][0] += dp[edges[cur][i]][1];
        dp[cur][1] += std::min(dp[edges[cur][i]][0], dp[edges[cur][i]][1]);
    }
}

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n = 0;
    std::cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u = 0, v = 0;
        std::cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(1);

    std::cout << std::min(dp[1][0], dp[1][1]) << "\n";

    return 0;
}
