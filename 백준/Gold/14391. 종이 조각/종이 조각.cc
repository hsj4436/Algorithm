#include <iostream>

int N, M;
int paper[4][4];
bool used[4][4];
std::pair<int, int> piece[4][4]; // {0, 1} - 가로 한칸, {1, 1} 세로 한칸
int answer = 0;

void cut(int x, int y) {
    if (x == N) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (piece[i][j].second != 0) {
                    if (piece[i][j].first == 0) {
                        int tmp = 0;
                        for (int a = 0; a < piece[i][j].second; a++) {
                            tmp *= 10;
                            tmp += paper[i][j + a];
                        }
                        sum += tmp;
                    } else {
                        int tmp = 0;
                        for (int a = 0; a < piece[i][j].second; a++) {
                            tmp *= 10;
                            tmp += paper[i + a][j];
                        }
                        sum += tmp;
                    }
                }
            }
        }
        answer = std::max(answer, sum);
        return;
    }
    if (used[x][y]) {
        if (y + 1 > M - 1) {
            cut(x + 1, 0);
        } else {
            cut(x, y + 1);
        }
        return;
    }
    for (int i = 1; i < M - y + 1; i++) {
        piece[x][y] = {0, i};
        bool possible = true;
        for (int j = 0; j < i; j++) {
            if (used[x][y + j]) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            piece[x][y] = {0, 0};
            if (y + i > M - 1) {
                cut(x + 1, 0);
            } else {
                cut(x, y + i);
            }
            continue;
        }
        for (int j = 0; j < i; j++) {
            used[x][y + j] = true;
        }
        if (y + i > M - 1) {
            cut(x + 1, 0);
        } else {
            cut(x, y + i);
        }
        for (int j = 0; j < i; j++) {
            used[x][y + j] = false;
        }
        piece[x][y] = {0, 0};
    }

    for (int i = 1; i < N - x + 1; i++) {
        piece[x][y] = {1, i};
        bool possible = true;
        for (int j = 0; j < i; j++) {
            if (used[x + j][y]) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            piece[x][y] = {0, 0};
            if (y + 1 > M - 1) {
                cut(x + 1, 0);
            } else {
                cut(x, y + 1);
            }
            continue;
        }
        for (int j = 0; j < i; j++) {
            used[x + j][y] = true;
        }
        if (y + 1 > M - 1) {
            cut(x + 1, 0);
        } else {
            cut(x, y + 1);
        }
        for (int j = 0; j < i; j++) {
            used[x + j][y] = false;
        }
        piece[x][y] = {0, 0};
    }
}

int main() {
    std::cin >> N >> M;

    std::string row;
    for (int i = 0; i < N; i++) {
        std::cin >> row;
        for (int j = 0; j < M; j++) {
            paper[i][j] = row[j] - '0';
        }
    }

    cut(0, 0);

    std::cout << answer << "\n";

    return 0;
}
