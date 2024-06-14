#include <iostream>
#include <queue>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N, M, K;
int aisle[101][101];
bool visited[101][101];

int main() {
    std::cin >> N >> M >> K;

    int x, y;
    for (int i = 0; i < K; i++) {
        std::cin >> x >> y;
        aisle[x][y] = 1;
    }

    int answer = 0;
    std::queue<std::pair<int, int>> q;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            if (!visited[i][j] && aisle[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = true;

                int size = 0;
                while (!q.empty()) {
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();
                    size++;

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 1 || nx > N || ny < 1 || ny > M) {
                            continue;
                        }
                        if (visited[nx][ny] || aisle[nx][ny] == 0) {
                            continue;
                        }
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
                answer = std::max(answer, size);
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}
