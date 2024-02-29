#include <iostream>

int M, N;
int home[701][701];
int growth[701][701];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            home[i][j] = 1;
        }
    }

    int zeros, ones, twos;
    for (int i = 0; i < N; i++) {
        std::cin >> zeros >> ones >> twos;
        for (int j = 0; j < M; j++) {
            if (zeros > 0) {
                zeros--;
                growth[M - 1 - j][0] += 0;
            } else if (ones > 0) {
                ones--;
                growth[M - 1 - j][0] += 1;
                home[M - 1 - j][0] += 1;
            } else {
                twos--;
                growth[M - 1 - j][0] += 2;
                home[M - 1 - j][0] += 2;
            }
        }
        for (int j = 1; j < M; j++) {
            if (zeros > 0) {
                zeros--;
                growth[0][j] += 0;
            } else if (ones > 0) {
                ones--;
                growth[0][j] += 1;
                home[0][j] += 1;
            } else {
                twos--;
                growth[0][j] += 2;
                home[0][j] += 2;
            }
        }
    }
    for (int j = 1; j < M; j++) {
        for (int k = 1; k < M; k++) {
            int max_growth = std::max(growth[j - 1][k - 1], std::max(growth[j - 1][k], growth[j][k - 1]));
            growth[j][k] = max_growth;
            home[j][k] += max_growth;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << home[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
