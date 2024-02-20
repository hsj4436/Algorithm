#include <iostream>

int N, M, K;
int cost[10001];
int parent[10001];

int find_parent(int x) {
    if (parent[x] < 0) {
        return x;
    } else {
        return parent[x] = find_parent(parent[x]);
    }
}

int main() {
    std::cin >> N >> M >> K;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> cost[i];
        parent[i] = -1;
    }

    int V, W;
    for (int i = 0; i < M; i++) {
        std::cin >> V >> W;

        int pV = find_parent(V);
        int pW = find_parent(W);

        if (pV == pW) {
            continue;
        }

        if (parent[pV] < parent[pW]) {
            parent[pV] += parent[pW];
            parent[pW] = pV;
            if (cost[pV] < cost[pW]) {
                cost[pW] = 0;
            } else {
                cost[pV] = cost[pW];
                cost[pW] = 0;
            }
        } else {
            parent[pW] += parent[pV];
            parent[pV] = pW;
            if (cost[pW] < cost[pV]) {
                cost[pV] = 0;
            } else {
                cost[pW] = cost[pV];
                cost[pV] = 0;
            }
        }
    }

    int total_cost = 0;
    int friends = 0;
    for (int i = 1; i < N + 1; i++) {
        if (parent[i] < 0) {
            if (total_cost + cost[i] > K) {
                std::cout << "Oh no\n";
                return 0;
            } else {
                total_cost += cost[i];
                friends -= parent[i];
            }
        }
    }

    std::cout << total_cost << "\n";

    return 0;
}
