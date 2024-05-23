#include <iostream>
#include <vector>
#include <queue>

#define PII std::pair<int, int>
#define WATER 0
#define SWAN 1
#define ICE 2

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int R, C;
int lake[1501][1501];
bool visited[1501][1501];
bool end = false;
PII swan;
std::queue<PII> swanQ, swanNQ;
std::queue<PII> waterQ, waterNQ;

int main() {
    std::cin >> R >> C;

    std::string row;
    for (int i = 0; i < R; i++) {
        std::cin >> row;
        for (int j = 0; j < C; j++) {
            if (row[j] == '.') {
                lake[i][j] = WATER;
                waterQ.push({i, j});
            } else if (row[j] == 'L') {
                swan = {i, j};
                lake[i][j] = SWAN;
                waterQ.push({i, j});
            } else {
                lake[i][j] = ICE;
            }
        }
    }

    int answer = 0;
    swanQ.push({swan.first, swan.second});
    visited[swan.first][swan.second] = true;

    while (!end) {
        while (!swanQ.empty() && !end) {
            int x = swanQ.front().first;
            int y = swanQ.front().second;
            swanQ.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1) {
                    continue;
                }
                if (visited[nx][ny]) {
                    continue;
                }
                if (lake[nx][ny] == WATER) {
                    visited[nx][ny] = true;
                    swanQ.push({nx, ny});
                } else if (lake[nx][ny] == SWAN) {
                    visited[nx][ny] = true;
                    end = true;
                    break;
                } else if (lake[nx][ny] == ICE) {
                    visited[nx][ny] = true;
                    swanNQ.push({nx, ny});
                }
            }
        }

        if (end) {
            continue;
        }
        while (!waterQ.empty()) {
            int x = waterQ.front().first;
            int y = waterQ.front().second;
            waterQ.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1) {
                    continue;
                }
                if (lake[nx][ny] == ICE) {
                    lake[nx][ny] = WATER;
                    waterNQ.push({nx, ny});
                }
            }
        }

        waterQ = waterNQ;
        swanQ = swanNQ;
        while (!waterNQ.empty()) {
            waterNQ.pop();
        }
        while (!swanNQ.empty()) {
            swanNQ.pop();
        }
        answer++;
    }

    std::cout << answer << "\n";

    return 0;
}
