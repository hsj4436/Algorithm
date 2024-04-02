#include <iostream>

int N, M;
int dist[501][501];

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        dist[b][a] = 1;
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
                dist[i][j] = std::max(dist[i][j], (dist[i][k] & dist[k][j]));
            }
        }
    }

    int answer = 0;
    for (int i = 1; i < N + 1; i++) {
        int count = 0;
        for (int j = 1; j < N + 1; j++) {
            if (i == j) {
                continue;
            }
            if (dist[i][j] > 0) {
                count++;
            }
            if (dist[j][i] > 0) {
                count++;
            }
        }
        if (count == N - 1) {
            answer++;
        }
    }

    std::cout << answer << "\n";
    return 0;
}
