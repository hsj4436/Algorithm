#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define PII std::pair<int, int>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int R, C;
int N;
int cave[101][101];
int clusters = 0;

void findClusters() {
    int localClusters = 1;
    std::queue<PII> q;
    bool visited[101][101];
    std::fill_n(&visited[0][0], 101 * 101, false);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (cave[i][j] != 0 && !visited[i][j]) {
                std::vector<PII> cluster;
                q.push({i, j});
                cluster.push_back({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1) {
                            continue;
                        }
                        if (visited[nx][ny] || cave[nx][ny] == 0) {
                            continue;
                        }
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                        cluster.push_back({nx, ny});
                    }
                }
                for (PII c : cluster) {
                    cave[c.first][c.second] = localClusters;
                }
                localClusters++;
            }
        }
    }
    clusters = localClusters - 1;
}

int main() {
    std::cin >> R >> C;

    std::string row;
    for (int i = 0; i < R; i++) {
        std::cin >> row;
        for (int j = 0; j < C; j++) {
            if (row[j] == '.') {
                cave[i][j] = 0;
            } else {
                cave[i][j] = 1;
            }
        }
    }

    findClusters();

    std::cin >> N;
    int stick;
    for (int i = 0; i < N; i++) {
        std::cin >> stick;
        stick = R - stick;

        if (i % 2 == 0) {
            for (int j = 0; j < C; j++) {
                if (cave[stick][j] != 0) {
                    cave[stick][j] = 0;
                    break;
                }
            }
        } else {
            for (int j = C - 1; j > -1; j--) {
                if (cave[stick][j] != 0) {
                    cave[stick][j] = 0;
                    break;
                }
            }
        }

        findClusters();

        std::map<int, std::vector<PII>> clusterGroup;
        for (int j = R - 1; j > -1; j--) {
            for (int k = 0; k < C; k++) {
                if (cave[j][k] != 0) {
                    clusterGroup[cave[j][k]].push_back({j, k});
                }
            }
        }
        for (auto p : clusterGroup) {
            int minDistance = 101;
            int clusterNumber = p.first;
            for (PII point : p.second) {
                int x = point.first;
                int y = point.second;
                if (x == R - 1) {
                    minDistance = 101;
                    break;
                }
                for (int j = x + 1; j < R; j++) {
                    if (cave[j][y] == clusterNumber) {
                        break;
                    }
                    if (cave[j][y] > 0 && cave[j][y] != clusterNumber) {
                        minDistance = std::min(minDistance, j - x - 1);
                        break;
                    }
                }
                if (minDistance == 101) {
                    minDistance = R - 1 - x;
                }
            }
            if (minDistance == 101) {
                continue;
            }
            for (PII point : p.second) {
                cave[point.first + minDistance][point.second] = cave[point.first][point.second];
                cave[point.first][point.second] = 0;
            }
        }
        findClusters();
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (cave[i][j] == 0) {
                std::cout << ".";
            } else {
                std::cout << "x";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
