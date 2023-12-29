#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <map>

int TC;
int H, W;
char building[101][101];
bool visited[101][101];
std::vector<std::pair<int, int>> entrances;
std::map<char, int> keys;
int answer = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    int move_count = 0;
    std::queue<std::pair<int, int>> trace;
    for (auto p : entrances) {
        trace.push(p);
        visited[p.first][p.second] = true;
    }

    while (!trace.empty()) {
        if (move_count >= 100 * H * W) {
            break;
        }

        auto cur = trace.front();
        trace.pop();

        if ('A' <= building[cur.first][cur.second] && building[cur.first][cur.second] <= 'Z') {
            if (keys[building[cur.first][cur.second] - 'A' + 'a'] == 0) {
                trace.push(cur);
                move_count++;
                continue;
            } else {
                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];

                    if (nx < 0 || nx > H - 1 || ny < 0 || ny > W - 1) {
                        continue;
                    }
                    if (visited[nx][ny] || building[nx][ny] == '*') {
                        continue;
                    }
                    if ('a' <= building[nx][ny] && building[nx][ny] <= 'z') {
                        keys[building[nx][ny]]++;
                        visited[nx][ny] = true;
                        move_count++;
                        trace.push({nx, ny});
                    } else if ('A' <= building[nx][ny] && building[nx][ny] <= 'Z') {
                        visited[nx][ny] = true;
                        move_count++;
                        trace.push({nx, ny});
                    } else if (building[nx][ny] == '.'){
                        visited[nx][ny] = true;
                        move_count++;
                        trace.push({nx, ny});
                    } else {
                        answer++;
                        visited[nx][ny] = true;
                        move_count++;
                        trace.push({nx, ny});
                    }
                }
                continue;
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx > H - 1 || ny < 0 || ny > W - 1) {
                continue;
            }
            if (visited[nx][ny] || building[nx][ny] == '*') {
                continue;
            }
            if ('a' <= building[nx][ny] && building[nx][ny] <= 'z') {
                keys[building[nx][ny]]++;
                visited[nx][ny] = true;
                move_count++;
                trace.push({nx, ny});
            } else if ('A' <= building[nx][ny] && building[nx][ny] <= 'Z') {
                visited[nx][ny] = true;
                move_count++;
                trace.push({nx, ny});
            } else if (building[nx][ny] == '.'){
                visited[nx][ny] = true;
                move_count++;
                trace.push({nx, ny});
            } else {
                answer++;
                visited[nx][ny] = true;
                move_count++;
                trace.push({nx, ny});
            }
        }
    }
}

int main() {
    std::cin >> TC;

    for (int tc = 0; tc < TC; tc++) {
        answer = 0;
        entrances.clear();
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                building[i][j] = '*';
                visited[i][j] = false;
            }
        }
        std::cin >> H >> W;
        for (int i = 0; i < H; i++) {
            std::string row;
            std::cin >> row;
            for (int j = 0; j < W; j++) {
                building[i][j] = row[j];
            }
        }
        std::string key;
        std::cin >> key;
        keys.clear();
        if (key != "0") {
            for (char ch : key) {
                keys[ch]++;
            }
        }

        for (int i = 0; i < W; i++) {
            if (building[0][i] != '*') {
                if (building[0][i] == '$') {
                    answer++;
                }
                if ('a' <= building[0][i] && building[0][i] <= 'z') {
                    keys[building[0][i]]++;
                }
                entrances.push_back({0, i});
            }
            if (building[H - 1][i] != '*') {
                if (building[H - 1][i] == '$') {
                    answer++;
                }
                if ('a' <= building[H - 1][i] && building[H - 1][i] <= 'z') {
                    keys[building[H - 1][i]]++;
                }
                entrances.push_back({H - 1, i});
            }
        }

        for (int i = 1; i < H - 1; i++) {
            if (building[i][0] != '*') {
                if (building[i][0] == '$') {
                    answer++;
                }
                if ('a' <= building[i][0] && building[i][0] <= 'z') {
                    keys[building[i][0]]++;
                }
                entrances.push_back({i, 0});
            }
            if (building[i][W - 1] != '*') {
                if (building[i][W - 1] == '$') {
                    answer++;
                }
                if ('a' <= building[i][W - 1] && building[i][W - 1] <= 'z') {
                    keys[building[i][W - 1]]++;
                }
                entrances.push_back({i, W - 1});
            }
        }

        bfs();

        std::cout << answer << "\n";
    }
    return 0;
}
