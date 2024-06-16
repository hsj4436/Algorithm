#include <iostream>
#include <vector>
#include <queue>

#define PII std::pair<int, int>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N, M, P;
int expandLimit[10];
int board[1001][1001];
int castleSize[10];
std::queue<std::pair<PII, int>> castle[10];
bool isEndPlayer[10];

int main() {
    std::cin >> N >> M >> P;

    for (int i = 1; i < P + 1; i++) {
        std::cin >> expandLimit[i];
    }

    char cell;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> cell;
            if (cell == '.') {
                board[i][j] = 0;
            } else if (cell == '#') {
                board[i][j] = -1;
            } else {
                board[i][j] = cell - '0';
                castleSize[cell - '0']++;
                castle[cell - '0'].push({{i, j}, expandLimit[cell - '0']});
            }
        }
    }

    while (true) {
        bool expanded = false;
        for (int player = 1; player < P + 1; player++) {
            if (isEndPlayer[player]) {
                continue;
            }
            bool expandedLocal = false;
            std::queue<std::pair<PII, int>> q = castle[player];
            while (!q.empty()) {
                int x = q.front().first.first;
                int y = q.front().first.second;
                int toExpand = q.front().second;
                q.pop();

                if (toExpand == expandLimit[player]) {
                    castle[player].pop();
                }

                if (toExpand == 0) {
                    continue;
                }

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
                        continue;
                    }
                    if (board[nx][ny] != 0) {
                        continue;
                    }
                    expandedLocal = true;
                    board[nx][ny] = player;
                    castleSize[player]++;
                    castle[player].push({{nx, ny}, expandLimit[player]});
                    q.push({{nx, ny}, toExpand - 1});
                }
            }
            if (!expandedLocal) {
                isEndPlayer[player] = true;
            } else {
                expanded = true;
            }
        }
        if (!expanded) {
            break;
        }
    }

    for (int i = 1; i < P + 1; i++) {
        std::cout << castleSize[i] << " ";
    }

    return 0;
}
