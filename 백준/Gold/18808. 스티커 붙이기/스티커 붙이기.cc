#include <iostream>

int N, M, K;
bool notebook[41][41];
bool stickers[101][4][11][11];

int main() {
    std::cin >> N >> M >> K;

    int R, C;
    for (int i = 0; i < K; i++) {
        std::cin >> R >> C;
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                std::cin >> stickers[i][0][j][k];
            }
        }
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                stickers[i][1][k][R - 1 - j] = stickers[i][0][j][k];
            }
        }
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                stickers[i][2][R - 1 - j][C - 1 - k] = stickers[i][0][j][k];
            }
        }
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                stickers[i][3][C - 1 - k][j] = stickers[i][0][j][k];
            }
        }
    }

    for (int i = 0; i < K; i++) {
        bool attached = false;
        for (int d = 0; d < 4; d++) {
            for (int x = 0; x < N; x++) {
                for (int y = 0; y < M; y++) {
                    bool can_attach = true;
                    for (int j = 0; j < 11; j++) {
                        for (int k = 0; k < 11; k++) {
                            if ((stickers[i][d][j][k] && (x + j > N - 1 || y + k > M - 1)) || stickers[i][d][j][k] && notebook[x + j][y + k]) {
                                can_attach = false;
                                break;
                            }
                        }
                        if (!can_attach) {
                            break;
                        }
                    }
                    if (can_attach) {
                        for (int j = 0; j < 11; j++) {
                            for (int k = 0; k < 11; k++) {
                                if (stickers[i][d][j][k]) {
                                    notebook[x + j][y + k] = true;
                                }
                            }
                        }
                        attached = true;
                        break;
                    }
                }
                if (attached) {
                    break;
                }
            }
            if (attached) {
                break;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (notebook[i][j]) {
                cnt++;
            }
        }
    }
    std::cout << cnt << "\n";

    return 0;
}
