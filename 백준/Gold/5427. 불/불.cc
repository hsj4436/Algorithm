#include <iostream>
#include <queue>

#define PII std::pair<int, int>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int TC;
int W, H;
char map[1001][1001];
bool visited[1001][1001];

int main() {
    std::cin >> TC;

    while (TC--) {
        std::fill_n(&visited[0][0], 1001 * 1001, false);
        std::queue<std::pair<PII, int>> SangGeun;
        std::queue<std::pair<PII, int>> fires;

        std::cin >> W >> H;

        std::string row;
        for (int i = 0; i < H; i++) {
            std::cin >> row;
            for (int j = 0; j < W; j++) {
                map[i][j] = row[j];
                if (map[i][j] == '*') {
                    visited[i][j] = true;
                    fires.push({{i, j}, 0});
                }
                if (map[i][j] == '@') {
                    visited[i][j] = true;
                    SangGeun.push({{i, j}, 0});
                    map[i][j] = '.';
                }
            }
        }

        int answer = 1000001;
        int t = 0;
        while (true) {
            if (SangGeun.empty()) {
                break;
            }
            while (!SangGeun.empty()) {
                PII cur = SangGeun.front().first;
                int curT = SangGeun.front().second;

                if (curT > t) {
                    break;
                }

                SangGeun.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];

                    if (nx < 0 || nx > H - 1 || ny < 0 || ny > W - 1) {
                        answer = curT + 1;
                        break;
                    }

                    if (visited[nx][ny] || map[nx][ny] == '#' || map[nx][ny] == '*') {
                        continue;
                    }
                    bool isPossibleCell = true;
                    for (int j = 0; j < 4; j++) {
                        int nnx = nx + dx[j];
                        int nny = ny + dy[j];
                        if (nnx < 0 || nnx > H - 1 || nny < 0 || nny > W - 1) {
                            continue;
                        }
                        if (map[nnx][nny] == '*') {
                            isPossibleCell = false;
                            break;
                        }
                    }
                    if (!isPossibleCell) {
                        continue;
                    }
                    visited[nx][ny] = true;
                    SangGeun.push({{nx, ny}, curT + 1});
                }
            }
            if (answer != 1000001) {
                break;
            }
            while (!fires.empty()) {
                PII cur = fires.front().first;
                int curT = fires.front().second;

                if (curT > t) {
                    break;
                }

                fires.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];

                    if (nx < 0 || nx > H - 1 || ny < 0 || ny > W - 1) {
                        continue;
                    }
                    if (map[nx][ny] == '#' || map[nx][ny] == '*') {
                        continue;
                    }
                    visited[nx][ny] = true;
                    map[nx][ny] = '*';
                    fires.push({{nx, ny}, curT + 1});
                }
            }
            t++;
        }
        if (answer != 1000001) {
            std::cout << answer << "\n";
        } else {
            std::cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}
