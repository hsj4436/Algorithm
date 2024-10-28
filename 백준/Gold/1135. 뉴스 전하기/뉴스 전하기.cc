#include <iostream>
#include <vector>
#include <algorithm>

int answer = 0;
int N;
int cost[51];
std::vector<int> company[51];

bool cmp(int &a, int &b) {
    return cost[a] > cost[b];
}

int dfs(int cur) {
    if (company[cur].size() == 0) {
        cost[cur] = 0;
        return cost[cur];
    }

    for (int next : company[cur]) {
        dfs(next);
    }

    std::sort(company[cur].begin(), company[cur].end(), cmp);

    for (int i = 0; i < company[cur].size(); i++) {
        cost[cur] = std::max(cost[company[cur][i]] + i + 1, cost[cur]);
    }

    return cost[cur];
}

int main() {
    std::cin >> N;

    int superior = 0;
    std::cin >> superior;
    for (int i = 1; i < N; i++) {
        std::cin >> superior;
        company[superior].push_back(i);
    }

    std::cout << dfs(0);

    return 0;
}
