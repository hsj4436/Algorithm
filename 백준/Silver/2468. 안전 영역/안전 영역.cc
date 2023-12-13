#include <iostream>
#include <cstring>
#include <queue>

int N;
int map[101][101];
bool visited[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y) {
    std::queue<std::pair<int, int>> trace;
    visited[x][y] = true;
    trace.push({x, y});

    while (!trace.empty()) {
        auto current = trace.front();
        trace.pop();

        for (int i = 0; i < 4; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];

            if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
                continue;
            }

            if (visited[nx][ny] || map[nx][ny] < 1) {
                continue;
            }

            visited[nx][ny] = true;
            trace.push({nx, ny});
        }
    }
}

int find_area() {
    std::memset(visited, false, sizeof(visited));
    int areas = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && map[i][j] > 0) {
                bfs(i, j);
                areas++;
            }
        }
    }

    return areas;
}

int main() {
    std::cin >> N;

    int min_height = 101;
    int max_height = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
            min_height = std::min(min_height, map[i][j]);
            max_height = std::max(max_height, map[i][j]);
        }
    }

    int ans = 1;
    for (int i = min_height; i < max_height; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                map[j][k] -= (i == min_height ? min_height : 1);
            }
        }

        ans = std::max(ans, find_area());
    }

    std::cout << ans << "\n";

    return 0;
}
