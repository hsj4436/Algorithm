#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

int N, M;
int parents[100001][20]; // {i, j} 노드 i의 2^j번째 부모 노드
int depth[100001];
std::vector<int> edges[100001];

int max_level;

void make_tree(int cur, int parent) {
    depth[cur] = depth[parent] + 1;
    parents[cur][0] = parent;

    max_level = (int)std::floor(std::log2(100001));

    for (int i = 1; i < max_level + 1; i++) {
        int tmp = parents[cur][i - 1];
        parents[cur][i] = parents[tmp][i - 1];
    }

    int len = edges[cur].size();
    for (int i = 0; i < len; i++) {
        int next = edges[cur][i];
        if (next != parent) {
            make_tree(next, cur);
        }
    }
}

int LCA(int a, int b) {
    if (depth[a] > depth[b]) {
        std::swap(a, b);
    }

    for (int i = max_level; i >= 0; i--) {
        if (depth[a] <= depth[parents[b][i]]) {
            b = parents[b][i];
        }
    }

    int lca = a;
    if (a != b) {
        for (int i = max_level; i >= 0; i--) {
            if (parents[a][i] != parents[b][i]) {
                a = parents[a][i];
                b = parents[b][i];
            }
            lca = parents[a][i];
        }
    }
    
    return lca;
}

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    int a, b;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    depth[0] = -1;
    make_tree(1, 0);

    std::cin >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> a >> b;
        std::cout << LCA(a, b) << "\n";
    }

    return 0;
}
