#include <iostream>

int N, M;
int woods[6][6];
bool used[6][6];
int answer = 0;

void back_track(int x, int y, int sum) {
    answer = std::max(answer, sum);
    for (int i = x; i < N; i++) {
        for (int j = (i == x ? y : 0); j < M; j++) {
            if (!used[i][j]) {
                if (i + 1 < N && j - 1 >= 0 && !used[i][j - 1] && !used[i + 1][j]) {
                    used[i][j] = true;
                    used[i][j - 1] = true;
                    used[i + 1][j] = true;
                    back_track(i, j, sum + 2 * woods[i][j] + woods[i][j - 1] + woods[i + 1][j]);
                    used[i][j] = false;
                    used[i][j - 1] = false;
                    used[i + 1][j] = false;
                }
                if (i - 1 >= 0 && j - 1 >= 0 && !used[i][j - 1] && !used[i - 1][j]) {
                    used[i][j] = true;
                    used[i][j - 1] = true;
                    used[i - 1][j] = true;
                    back_track(i, j, sum + 2 * woods[i][j] + woods[i][j - 1] + woods[i - 1][j]);
                    used[i][j] = false;
                    used[i][j - 1] = false;
                    used[i - 1][j] = false;
                }
                if (i - 1 >= 0 && j + 1 < M && !used[i - 1][j] && !used[i][j + 1]) {
                    used[i][j] = true;
                    used[i][j + 1] = true;
                    used[i - 1][j] = true;
                    back_track(i, j, sum + 2 * woods[i][j] + woods[i][j + 1] + woods[i - 1][j]);
                    used[i][j] = false;
                    used[i][j + 1] = false;
                    used[i - 1][j] = false;
                }
                if (i + 1 < N && j + 1 < M && !used[i][j + 1] && !used[i + 1][j]) {
                    used[i][j] = true;
                    used[i][j + 1] = true;
                    used[i + 1][j] = true;
                    back_track(i, j, sum + 2 * woods[i][j] + woods[i][j + 1] + woods[i + 1][j]);
                    used[i][j] = false;
                    used[i][j + 1] = false;
                    used[i + 1][j] = false;
                }
            }
        }
    }
    answer = std::max(answer, sum);
}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> woods[i][j];
        }
    }

    back_track(0, 0, 0);

    std::cout << answer << "\n";
    return 0;
}
