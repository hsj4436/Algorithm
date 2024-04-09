#include <iostream>

struct info {
    int J;
    int O;
    int I;
    info() {}
    info(int J, int O, int I) : J(J), O(O), I(I) {}
};

int M, N, K;
char map[1001][1001];
info sum[1001][1001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    std::cin >> M >> N >> K;

    for (int i = 1; i < M + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            std::cin >> map[i][j];
        }
    }

    for (int i = 1; i < M + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            info upper = sum[i - 1][j];
            info left = sum[i][j - 1];
            info diag = sum[i - 1][j - 1];
            info cur;
            if (map[i][j] == 'I') {
                cur = info(0, 0, 1);
            } else if (map[i][j] == 'O') {
                cur = info(0, 1, 0);
            } else {
                cur = info(1, 0, 0);
            }
            sum[i][j] = info(upper.J + left.J - diag.J + cur.J, upper.O + left.O - diag.O + cur.O, upper.I + left.I - diag.I + cur.I);
        }
    }

    int A, B, C, D;
    for (int i = 0; i < K; i++) {
        std::cin >> A >> B >> C >> D;
        info RB = sum[C][D];
        info RT = sum[A - 1][D];
        info LB = sum[C][B - 1];
        info diag = sum[A - 1][B - 1];
        int jungle = RB.J - RT.J - LB.J + diag.J;
        int ocean = RB.O - RT.O - LB.O + diag.O;
        int ice = RB.I - RT.I - LB.I + diag.I;
        std::cout << jungle << " " << ocean << " " << ice << "\n";
    }
    return 0;
}
