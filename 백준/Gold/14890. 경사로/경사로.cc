#include <iostream>

int N, L;
int map[101][101];
bool row_installed[101][101];
bool col_installed[101][101];

int main() {
    std::cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool passable = true;
        for (int j = 0; j < N; j++) {
            if (j == N - 1 || map[i][j] == map[i][j + 1]) {
                continue;
            }
            if (std::abs(map[i][j] - map[i][j + 1]) > 1) {
                passable = false;
                break;
            }
            if (map[i][j] < map[i][j + 1]) {
                if (j - L + 1 < 0) {
                    passable = false;
                    break;
                }
                for (int k = j - L + 1; k < j; k++) {
                    if (map[i][k] != map[i][k + 1] || row_installed[i][k]) {
                        passable = false;
                        break;
                    }
                }
                if (row_installed[i][j]) {
                    passable = false;
                    break;
                }
                if (!passable) {
                    break;
                }
                for (int k = j - L + 1; k < j + 1; k++) {
                    row_installed[i][k] = true;
                }
            } else {
                if (j + L > N - 1) {
                    passable = false;
                    break;
                }
                for (int k = j + 1; k < j + L; k++) {
                    if (map[i][k] != map[i][k + 1] || row_installed[i][k]) {
                        passable = false;
                        break;
                    }
                }
                if (row_installed[i][j + L]) {
                    passable = false;
                    break;
                }
                if (!passable) {
                    break;
                }
                for (int k = j + 1; k < j + L + 1; k++) {
                    row_installed[i][k] = true;
                }
            }
        }
        if (passable) {
            ans++;
        }
    }

    for (int i = 0; i < N; i++) {
        bool passable = true;
        for (int j = 0; j < N; j++) {
            if (j == N - 1 || map[j][i] == map[j + 1][i]) {
                continue;
            }
            if (std::abs(map[j][i] - map[j + 1][i]) > 1) {
                passable = false;
                break;
            }
            if (map[j][i] < map[j + 1][i]) {
                if (j - L + 1 < 0) {
                    passable = false;
                    break;
                }
                for (int k = j - L + 1; k < j; k++) {
                    if (map[k][i] != map[k + 1][i] || col_installed[k][i]) {
                        passable = false;
                        break;
                    }
                }
                if (col_installed[j][i]) {
                    passable = false;
                    break;
                }
                if (!passable) {
                    break;
                }
                for (int k = j - L + 1; k < j + 1; k++) {
                    col_installed[k][i] = true;
                }
            } else {
                if (j + L > N - 1) {
                    passable = false;
                    break;
                }
                for (int k = j + 1; k < j + L; k++) {
                    if (map[k][i] != map[k + 1][i] || col_installed[k][i]) {
                        passable = false;
                        break;
                    }
                }
                if (col_installed[j + L][i]) {
                    passable = false;
                    break;
                }
                if (!passable) {
                    break;
                }
                for (int k = j + 1; k < j + L + 1; k++) {
                    col_installed[k][i] = true;
                }
            }
        }
        if (passable) {
            ans++;
        }
    }

    std::cout << ans << "\n";

    return 0;
}