#include <iostream>
#include <vector>
#include <algorithm>

int X;
int M, N;
int A[1001][1001]; // {i, j} size of j pieces start from i
int B[1001][1001];

int main() {
    std::cin >> X;
    std::cin >> M >> N;
    for (int i = 0; i < M; i++) {
        std::cin >> A[i][1];
    }
    std::vector<int> Bs;
    for (int i = 0; i < N; i++) {
        std::cin >> B[i][1];
        Bs.push_back(B[i][1]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 2; j < N; j++) {
            B[i][j] = B[i][j - 1] + B[(i + j - 1) % N][1];
            Bs.push_back(B[i][j]);
        }
    }
    Bs.push_back(B[0][N - 1] + B[N - 1][1]);
    std::sort(Bs.begin(), Bs.end());

    int answer = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 1; j < M; j++) {
            if (j > 1) {
                A[i][j] = A[i][j - 1] + A[(i + j - 1) % M][1];
            }
            if (A[i][j] > X) {
                continue;
            }
            if (A[i][j] == X) {
                answer++;
                continue;
            }
            answer += std::upper_bound(Bs.begin(), Bs.end(), X - A[i][j]) - std::lower_bound(Bs.begin(), Bs.end(), X - A[i][j]);
        }
    }
    if (A[0][M - 1] + A[M - 1][1] < X) {
        answer += std::upper_bound(Bs.begin(), Bs.end(), X - (A[0][M - 1] + A[M - 1][1])) - std::lower_bound(Bs.begin(), Bs.end(), X - (A[0][M - 1] + A[M - 1][1]));
    } else if (A[0][M - 1] + A[M - 1][1] == X) {
        answer++;
    }
    answer += std::upper_bound(Bs.begin(), Bs.end(), X) - std::lower_bound(Bs.begin(), Bs.end(), X);

    std::cout << answer << "\n";

    return 0;
}
