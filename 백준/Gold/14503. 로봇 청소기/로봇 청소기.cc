#include <iostream>

int N, M;
int room[51][51];
bool visited[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int answer = 0;

void clean(int x, int y, int direction, bool back) {
    if (!back && visited[x][y]) {
        return;
    }

    if (!visited[x][y]) {
        visited[x][y] = true;
        answer++;
    }

    bool all_clean = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (room[nx][ny] == 0 && !visited[nx][ny]) {
            all_clean = false;
            break;
        }
    }

    if (!all_clean) {
        int nx = x + dx[(direction - 1 < 0) ? (direction - 1) % 4 + 4 : (direction - 1) % 4];
        int ny = y + dy[(direction - 1 < 0) ? (direction - 1) % 4 + 4 : (direction - 1) % 4];

        if (room[nx][ny] == 0 && !visited[nx][ny]) {
            clean(nx, ny, (direction - 1 < 0) ? (direction - 1) % 4 + 4 : (direction - 1) % 4, false);
        } else {
            clean(x, y, (direction - 1 < 0) ? (direction - 1) % 4 + 4 : (direction - 1) % 4, true);
        }
        return;
    }

    int nx = x + dx[(direction + 2) % 4];
    int ny = y + dy[(direction + 2) % 4];
    if (room[nx][ny] == 0) {
        clean(nx, ny, direction, true);
    }
}

int main() {
    std::cin >> N >> M;

    int x, y, d;
    std::cin >> x >> y >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> room[i][j];
        }
    }

    clean(x, y, d, false);

    std::cout << answer << "\n";

    return 0;
}
