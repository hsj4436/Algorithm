#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
#define PII std::pair<int, int>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N, M, F;
int map[21][21];
int distances[21][21][21][21];
bool visited[21][21];
PII taxi = {0, 0};
std::vector<std::pair<PII, PII>> caller; // {departure, arrival}
bool hasTransported[401];

void getDistance(int x, int y) {
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            visited[i][j] = false;
        }
    }
    visited[x][y] = true;
    distances[x][y][x][y] = 0;
    std::queue<std::pair<int, PII>> q;
    q.push({0, {x, y}});
    while (!q.empty()) {
        int d = q.front().first;
        int curX = q.front().second.first;
        int curY = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if (nx < 1 || nx > N || ny < 1 || ny > N) {
                continue;
            }
            if (map[nx][ny] == 1) {
                continue;
            }
            if (visited[nx][ny]) {
                if (d + 1 < distances[x][y][nx][ny]) {
                    distances[x][y][nx][ny] = d + 1;
                    q.push({d + 1, {nx, ny}});
                }
                continue;
            }
            visited[nx][ny] = true;
            distances[x][y][nx][ny] = d + 1;
            q.push({d + 1, {nx, ny}});
        }
    }
}

int main () {
    std::cin >> N >> M >> F;

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            std::cin >> map[i][j];
        }
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (map[i][j] == 1) {
                continue;
            }
            for (int x = 1; x < N + 1; x++) {
                for (int y = 1; y < N + 1; y++) {
                    distances[i][j][x][y] = INF;
                }
            }
            getDistance(i, j);
        }
    }

    std::cin >> taxi.first >> taxi.second;
    caller.resize(M);
    for (int i = 0; i < M; i++) {
        std::cin >> caller[i].first.first >> caller[i].first.second >> caller[i].second.first >> caller[i].second.second;
    }

    int transported = 0;
    while (transported != M) {
        int minDistance = 987654321;
        int cIndex = -1;
        int cX = 21, cY = 21;
        for (int i = 0; i < caller.size(); i++) {
            if (hasTransported[i]) {
                continue;
            }
            int d = distances[taxi.first][taxi.second][caller[i].first.first][caller[i].first.second];
            if (d == 0 && taxi.first != caller[i].first.first && taxi.second != caller[i].first.second) {
                continue;
            }
            if (d == INF) {
                continue;
            }
            if (d < minDistance) {
                minDistance = d;
                cX = caller[i].first.first;
                cY = caller[i].first.second;
                cIndex = i;
            } else if (d == minDistance) {
                if (caller[i].first.first < cX) {
                    cX = caller[i].first.first;
                    cY = caller[i].first.second;
                    cIndex = i;
                } else if (caller[i].first.first == cX && caller[i].first.second < cY) {
                    cX = caller[i].first.first;
                    cY = caller[i].first.second;
                    cIndex = i;
                }
            }
        }

        if (cIndex == -1) {
            std::cout << "-1\n";
            return 0;
        }

        if (F - distances[taxi.first][taxi.second][cX][cY] - distances[cX][cY][caller[cIndex].second.first][caller[cIndex].second.second] < 0) {
            std::cout << "-1\n";
            return 0;
        }

        F -= distances[taxi.first][taxi.second][cX][cY];
        F += distances[cX][cY][caller[cIndex].second.first][caller[cIndex].second.second];
        hasTransported[cIndex] = true;
        transported++;
        taxi = {caller[cIndex].second.first, caller[cIndex].second.second};
    }

    std::cout << F << "\n";
    return 0;
}