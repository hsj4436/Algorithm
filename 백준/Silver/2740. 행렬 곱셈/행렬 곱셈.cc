#include <iostream>

int N, M, K;
int A[101][101];
int B[101][101];
int AB[101][101];

int main() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }
    std::cin >> M >> K;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            std::cin >> B[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) {
                AB[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            std::cout << AB[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
