#include <iostream>

int N, M;
bool dist[101][101];

int main() {
    std::cin >> N >> M;

    int heavy, light;
    for (int i = 0; i < M; i++) {
        std::cin >> heavy >> light;
        dist[heavy][light] = true;
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
                dist[i][j] |= (dist[i][k] && dist[k][j]);
            }
        }
    }

    int answer = 0;
    for (int i = 1; i < N + 1; i++) {
        int heavier = 0, lighter = 0;
        for (int j = 1; j < N + 1; j++) {
            if (i == j) {
                continue;
            }
            if (dist[j][i]) {
                heavier++;
            }
            if (dist[i][j]) {
                lighter++;
            }
        }
        if (lighter > N / 2 || heavier > N / 2) {
            answer++;
        }
    }

    std::cout << answer << "\n";

    return 0;
}
