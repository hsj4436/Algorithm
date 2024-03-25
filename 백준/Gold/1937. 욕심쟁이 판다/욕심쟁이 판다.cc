#include <iostream>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N;
int forest[500][500];
int path[500][500];

int dfs(int x, int y) {
    path[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
            continue;
        }

        if (forest[nx][ny] <= forest[x][y]) {
            continue;
        }

        if (path[nx][ny] != 0) {
            path[x][y] = std::max(path[x][y], path[nx][ny] + 1);
            continue;
        }

        path[x][y] = std::max(path[x][y], dfs(nx, ny) + 1);
    }

    if (path[x][y] == 0) {
        return path[x][y] = 1;
    } else {
        return path[x][y];
    }
}

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> forest[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (path[i][j] != 0) {
                answer = std::max(answer, path[i][j]);
            } else {
                answer = std::max(answer, dfs(i, j));
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}