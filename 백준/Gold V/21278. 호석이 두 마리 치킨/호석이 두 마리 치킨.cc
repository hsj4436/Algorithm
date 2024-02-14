#include <iostream>

#define INF 10000000

int N, M;
int distance[101][101];

int main() {
    std::fill(&distance[0][0], &distance[100][101], INF);

    std::cin >> N >> M;

    int A, B;
    for (int i = 0; i < M; i++) {
        std::cin >> A >> B;
        distance[A][B] = 1;
        distance[B][A] = 1;
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
                distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    int minimum = INF;
    int first_index = 0, second_index = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j < N + 1; j++) {
            int sum = 0;
            for (int a = 1; a < N + 1; a++) {
                if (a == i || a == j) {
                    continue;
                }
                sum += std::min(distance[a][i] * 2, distance[a][j] * 2);
            }
            if (sum < minimum) {
                minimum = sum;
                first_index = i;
                second_index = j;
            }
        }
    }

    std::cout << first_index << " " << second_index << " " << minimum << "\n";

    return 0;
}
