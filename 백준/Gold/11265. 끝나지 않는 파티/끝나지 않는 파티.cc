#include <iostream>

int N, M;
int adj[501][501];
int A, B, C;

int main() {
    std::cin >> N >> M;

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            std::cin >> adj[i][j];
        }
    }

    for (int k = 1; k < N + 1; k++) {
        for (int i = 1; i < N + 1; i++) {
            if (i == k) {
                continue;
            }
            for (int j = 1; j < N + 1; j++) {
                if (i == j || j == k) {
                    continue;
                }
                adj[i][j] = std::min(adj[i][k] + adj[k][j], adj[i][j]);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        std::cin >> A >> B >> C;
        if (adj[A][B] <= C) {
            std::cout << "Enjoy other party\n";
        } else {
            std::cout << "Stay here\n";
        }
    }
    return 0;
}
