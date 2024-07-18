#include <iostream>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int R, C, K;
int map[5][5];
bool visited[5][5];
int answer = 0;

void dfs(int x, int y, int moved) {
    if (x == 0 && y == C - 1) {
        if (moved == K) {
            answer++;
        }
        return;
    }

    if (moved > K) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1) {
            continue;
        }
        if (visited[nx][ny]) {
            continue;
        }
        if (map[nx][ny] == 1) {
            continue;
        }
        visited[nx][ny] = true;
        dfs(nx, ny, moved + 1);
        visited[nx][ny] = false;
    }
}

int main() {
    std::cin >> R >> C >> K;
    std::string row;
    for (int i = 0; i < R; i++) {
        std::cin >> row;
        for (int j = 0; j < C; j++) {
            if (row[j] == '.') {
                map[i][j] = 0;
            } else {
                map[i][j] = 1;
            }
        }
    }

    visited[R - 1][0] = true;
    dfs(R - 1, 0, 1);

    std::cout << answer << "\n";

    return 0;
}
