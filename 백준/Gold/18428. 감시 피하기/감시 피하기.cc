#include <iostream>

int N;
char map[7][7];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool is_student_visible(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x;
        int ny = y;
        while (true) {
            nx = dx[i] == 0 ? nx : nx + dx[i];
            ny = dy[i] == 0 ? ny : ny + dy[i];
            if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
                break;
            }
            if (map[nx][ny] == 'O') {
                break;
            }
            if (map[nx][ny] == 'S') {
                return false;
            }
        }
    }

    return true;
}

bool back_track(int x, int y, int cnt) {
    if (cnt == 3) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 'T') {
                    if (!is_student_visible(i, j)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    for (int i = x; i < N; i++) {
        for (int j = i == x ? y : 0; j < N; j++) {
            if (map[i][j] == 'X') {
                map[i][j] = 'O';
                if (back_track(j == N - 1 ? x + 1 : x, y + 1, cnt + 1)) {
                    return true;
                }
                map[i][j] = 'X';
            }
        }
    }

    return false;
}

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }

    if (back_track(0, 0, 0)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
