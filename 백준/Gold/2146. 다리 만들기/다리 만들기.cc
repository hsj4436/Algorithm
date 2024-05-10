#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <cstring>

int N;
bool map[101][101];
int visited[101][101];
std::map<int, std::queue<std::pair<std::pair<int, int>, int>>> borders;
bool b_visited[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int island_count = 1;
int ans = 987654321;

void bfs(int sx, int sy) {
    std::queue<std::pair<int, int>> trace;
    trace.push({sx, sy});
    visited[sx][sy] = island_count;

    while (!trace.empty()) {
        auto cur = trace.front();
        trace.pop();

        bool is_border = false;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
                continue;
            }
            if (map[nx][ny] == 0) {
                is_border = true;
                continue;
            }
            if (visited[nx][ny] == island_count) {
                continue;
            }

            visited[nx][ny] = island_count;
            trace.push({nx, ny});
        }

        if (is_border) {
            borders[island_count].push({cur, 0});
        }
    }
}

void get_dist(int ic) {
    while (!borders[ic].empty()) {
        auto cur = borders[ic].front().first;
        int dist = borders[ic].front().second;
        borders[ic].pop();

        if (dist > ans) {
            while (!borders[ic].empty()) {
                borders[ic].pop();
            }
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
                continue;
            }
            if (map[nx][ny] == 1 && visited[nx][ny] != 0 && visited[nx][ny] != ic) {
                ans = std::min(ans, dist);
                while (!borders[ic].empty()) {
                    borders[ic].pop();
                }
                return;
            }
            if (visited[nx][ny] == ic) {
                continue;
            }
            if (b_visited[nx][ny]) {
                continue;
            }
            if (map[nx][ny] == 1) {
                continue;
            }
            b_visited[nx][ny] = true;
            borders[ic].push({{nx, ny}, dist + 1});
        }
    }
}

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0 && map[i][j] == 1) {
                bfs(i, j);
                island_count++;
            }
        }
    }

    for (int i = 1; i < island_count; i++) {
        std::memset(b_visited, false, sizeof(b_visited));
        get_dist(i);
    }

    std::cout << ans << "\n";

    return 0;
}
