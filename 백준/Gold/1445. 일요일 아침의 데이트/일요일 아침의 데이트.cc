#include <iostream>
#include <queue>

#define PII std::pair<int, int>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N, M;
int forest[51][51];
PII visited[51][51];
PII start;
PII flower;

int main() {
    std::cin >> N >> M;

    std::string row;
    for (int i = 0; i < N; i++) {
        std::cin >> row;
        for (int j = 0; j < M; j++) {
            if (row[j] == '.') {
                forest[i][j] = 0;
            } else if (row[j] == 'g') {
                forest[i][j] = -1;
            } else if (row[j] == 'S') {
                start = {i, j};
                forest[i][j] = 0;
            } else {
                flower = {i, j};
                forest[i][j] = 0;
            }
            visited[i][j] = {9999, 9999};
        }
    }

    std::queue<std::pair<PII, PII>> q;
    q.push({start, {0, 0}});
    visited[start.first][start.second] = {0, 0};

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int g1 = q.front().second.first;
        int g2 = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
                continue;
            }

            if (nx == flower.first && ny == flower.second) {
                if (g1 < visited[nx][ny].first || (g1 == visited[nx][ny].first && g2 < visited[nx][ny].second)) {
                    visited[nx][ny] = {g1, g2};
                }
                continue;
            }

            if (forest[nx][ny] == 0) {
                int garbage = 0;
                for (int j = 0; j < 4; j++) {
                    int nnx = nx + dx[j];
                    int nny = ny + dy[j];
                    if (nnx < 0 || nnx > N - 1 || nny < 0 || nny > M - 1) {
                        continue;
                    }
                    if (forest[nnx][nny] == -1) {
                        garbage++;
                    }
                }
                if (garbage == 0) {
                    if ((g1 < visited[nx][ny].first) || (g1 == visited[nx][ny].first && g2 < visited[nx][ny].second)) {
                        visited[nx][ny] = {g1, g2};
                        q.push({{nx, ny}, {g1, g2}});
                    }
                } else {
                    if ((g1 < visited[nx][ny].first) || (g1 == visited[nx][ny].first && g2 + 1 < visited[nx][ny].second)) {
                        visited[nx][ny] = {g1, g2 + 1};
                        q.push({{nx, ny}, {g1, g2 + 1}});
                    }
                }
            } else {
                if ((g1 + 1 < visited[nx][ny].first) || (g1 + 1 == visited[nx][ny].first && g2 < visited[nx][ny].second)) {
                    visited[nx][ny] = {g1 + 1, g2};
                    q.push({{nx, ny}, {g1 + 1, g2}});
                }
            }
        }
    }

    std::cout << visited[flower.first][flower.second].first << " " << visited[flower.first][flower.second].second << "\n";

    return 0;
}
