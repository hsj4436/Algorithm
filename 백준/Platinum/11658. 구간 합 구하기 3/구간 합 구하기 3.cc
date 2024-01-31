#include <iostream>

int N, M;
int table[1026][1026];
int sum[1026][1026];
int W, X, Y, C, X1, Y1, X2, Y2;

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> M;

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            std::cin >> table[i][j];
            sum[i][j] += table[i][j] + sum[i][j - 1];
        }
    }

    for (int i = 0; i < M; i++) {
        std::cin >> W;
        if (W == 0) {
            std::cin >> X >> Y >> C;
            int diff = C - table[X][Y];
            for (int j = Y; j < N + 1; j++) {
                sum[X][j] += diff;
            }
            table[X][Y] = C;
        } else {
            std::cin >> X1 >> Y1 >> X2 >> Y2;
            int answer = 0;
            for (int j = X1; j < X2 + 1; j++) {
                answer += sum[j][Y2] - sum[j][Y1 - 1];
            }
            std::cout << answer << "\n";
        }
    }
    return 0;
}
