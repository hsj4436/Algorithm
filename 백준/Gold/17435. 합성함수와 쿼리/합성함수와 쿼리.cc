#include <iostream>

int M, Q;
int sparseTable[20][200001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> M;
    for (int i = 1; i < M + 1; i++) {
        std::cin >> sparseTable[0][i];
    }

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < M + 1; j++) {
            sparseTable[i][j] = sparseTable[i - 1][sparseTable[i - 1][j]];
        }
    }

    std::cin >> Q;
    int N, X;
    for (int i = 0; i < Q; i++) {
        std::cin >> N >> X;
        for (int j = 0; j < 20; j++) {
            if ((N & (1 << j)) != 0) {
                X = sparseTable[j][X];
            }
        }
        std::cout << X << "\n";
    }
    return 0;
}
