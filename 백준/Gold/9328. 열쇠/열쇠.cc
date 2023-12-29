#include <iostream>
#include <queue>
#include <vector>
#include <map>

int TC;
int H, W;
char building[101][101];
bool visited[101][101];
std::vector<std::pair<int, int>> entrances;
bool keys[26];
std::queue<std::pair<int, int>> blocked[26];
int answer = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void init() {
    answer = 0;
    
    entrances.clear();
    
    for (int i = 0; i < 26; i++) {
        while (!blocked[i].empty()) {
            blocked[i].pop();
        }
    }
    
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            building[i][j] = '*';
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < 26; i++) {
        keys[i] = false;
    }
}

void bfs() {
    std::queue<std::pair<int, int>> trace;
    for (auto p : entrances) {
        if ('A' <= building[p.first][p.second] && building[p.first][p.second] <= 'Z') {
            if (keys[building[p.first][p.second] - 'A']) {
                visited[p.first][p.second] = true;
                trace.push(p);
            } else {
                blocked[building[p.first][p.second] - 'A'].push(p);
            }
        } else {
            visited[p.first][p.second] = true;
            trace.push(p);
        }
    }

    while (!trace.empty()) {
        auto cur = trace.front();
        trace.pop();

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
                keys[building[nx][ny] - 'a'] = true;
                visited[nx][ny] = true;
                while (!blocked[building[nx][ny] - 'a'].empty()) {
                    auto key_point = blocked[building[nx][ny] - 'a'].front();
                    blocked[building[nx][ny] - 'a'].pop();
                    visited[key_point.first][key_point.second] = true;
                    trace.push(key_point);
                }
                trace.push({nx, ny});
            } else if ('A' <= building[nx][ny] && building[nx][ny] <= 'Z') {
                if (keys[building[nx][ny] - 'A']) {
                    visited[nx][ny] = true;
                    trace.push({nx, ny});
                } else {
                    blocked[building[nx][ny] - 'A'].push({nx, ny});
                }
            } else if (building[nx][ny] == '.'){
                visited[nx][ny] = true;
                trace.push({nx, ny});
            } else {
                answer++;
                visited[nx][ny] = true;
                trace.push({nx, ny});
            }
        }
    }
}

int main() {
    std::cin >> TC;

    for (int tc = 0; tc < TC; tc++) {
        init();
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
        if (key != "0") {
            for (char ch : key) {
                keys[ch - 'a'] = true;
            }
        }

        for (int i = 0; i < W; i++) {
            if (building[0][i] != '*') {
                if (building[0][i] == '$') {
                    answer++;
                }
                if ('a' <= building[0][i] && building[0][i] <= 'z') {
                    keys[building[0][i] - 'a'] = true;
                }
                entrances.push_back({0, i});
            }
            if (building[H - 1][i] != '*') {
                if (building[H - 1][i] == '$') {
                    answer++;
                }
                if ('a' <= building[H - 1][i] && building[H - 1][i] <= 'z') {
                    keys[building[H - 1][i] - 'a'] = true;
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
                    keys[building[i][0] - 'a'] = true;
                }
                entrances.push_back({i, 0});
            }
            if (building[i][W - 1] != '*') {
                if (building[i][W - 1] == '$') {
                    answer++;
                }
                if ('a' <= building[i][W - 1] && building[i][W - 1] <= 'z') {
                    keys[building[i][W - 1] - 'a'] = true;
                }
                entrances.push_back({i, W - 1});
            }
        }

        bfs();

        std::cout << answer << "\n";
    }
    return 0;
}
