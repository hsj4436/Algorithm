#include <iostream>

int N, M;
char board[51][51];
bool visited[51][51];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool dfs(int x, int y, int sx, int sy, int length) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
            continue;
        }

        if (visited[nx][ny]) {
            if (board[nx][ny] == board[sx][sy]) {
                if (nx == sx && ny == sy) {
                    if (length >= 4) {
                        return true;
                    }
                }
            }
            continue;
        }

        if (board[nx][ny] == board[x][y]) {
            visited[nx][ny] = true;
            if (dfs(nx, ny, sx, sy, length + 1)) {
                return true;
            }
            visited[nx][ny] = false;
        }
    }

    return false;
}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::string row;
        std::cin >> row;
        for (int j = 0; j < M; j++) {
            board[i][j] = row[j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            if (dfs(i, j, i, j, 1)) {
                std::cout << "Yes\n";
                return 0;
            }
            visited[i][j] = false;
        }
    }

    std::cout << "No\n";

    return 0;
}