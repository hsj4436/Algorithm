#include <iostream>
#include <queue>

#define PII std::pair<int, int>

int dx[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[8] = {0, -1, 0, 1, 1, -1, 1, -1};

int N, M;
int farm[101][71];
bool visited[101][71];
bool is_top = true;
int answer = 0;

void bfs(int x, int y) {
    std::queue<PII> q;
    visited[x][y] = true;
    q.push({x, y});

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
                continue;
            }

            if (farm[x][y] < farm[nx][ny]) {
                is_top = false;
            }

            if (visited[nx][ny] || farm[x][y] != farm[nx][ny]) {
                continue;
            }

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> farm[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                is_top = true;
                bfs(i, j);
                if (is_top) {
                    answer++;
                }
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}