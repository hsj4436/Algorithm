#include <iostream>
#include <vector>
#include <queue>

struct unit {
    int x;
    int y;
    int moved;
    unit() {}
    unit(int x, int y, int moved) : x(x), y(y), moved(moved) {}
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N, M, A, B, K;
int map[501][501];
bool visited[501][501];

int main() {
    std::cin >> N >> M >> A >> B >> K;

    int x, y;
    for (int i = 0; i < K; i++) {
        std::cin >> x >> y;
        map[x][y] = 1;
    }

    int SX, SY;
    std::cin >> SX >> SY;
    visited[SX][SY] = true;
    unit initial = unit(SX, SY, 0);

    int EX, EY;
    std::cin >> EX >> EY;
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            if (map[EX + i][EY + j] == 1) {
                std::cout << "-1\n";
                return 0;
            }
        }
    }

    std::queue<unit> q;
    q.push(initial);

    while (!q.empty()) {
        unit cur = q.front();
        q.pop();

        if (cur.x == EX && cur.y == EY) {
            std::cout << cur.moved << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 1 || nx + A - 1 > N || ny < 1 || ny + B - 1 > M) {
                continue;
            }
            if (visited[nx][ny]) {
                continue;
            }
            bool possible = true;
            for (int a = 0; a < A; a++) {
                for (int b = 0; b < B; b++) {
                    if (map[nx + a][ny + b] == 1) {
                        possible = false;
                        break;
                    }
                }
            }
            if (possible) {
                visited[nx][ny] = true;
                q.push(unit(nx, ny, cur.moved + 1));
            }
        }
    }

    std::cout << "-1\n";

    return 0;
}
