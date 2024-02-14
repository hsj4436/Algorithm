#include <iostream>
#include <queue>

#define PII std::pair<int, int>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N, M;
char board[11][11];

int main() {
    std::cin >> N >> M;

    std::queue<std::pair<std::pair<PII, PII>, int>> q;
    PII red, blue;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> board[i][j];
            if (board[i][j] == 'R') {
                red = {i, j};
                board[i][j] = '.';
            } else if (board[i][j] == 'B') {
                blue = {i, j};
                board[i][j] = '.';
            }
        }
    }

    q.push({{red, blue}, 0});
    while (!q.empty()) {
        red = q.front().first.first;
        blue = q.front().first.second;
        int count = q.front().second;
        q.pop();

        if (count == 10) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int bx = blue.first;
            int by = blue.second;
            int rx = red.first;
            int ry = red.second;
            while (true) {
                bool moved = false;
                if (board[bx][by] != 'O') {
                    if (board[bx + dx[i]][by + dy[i]] != '#' && (!(bx + dx[i] == rx && by + dy[i] == ry) || board[bx + dx[i]][by + dy[i]] == 'O')) {
                        bx += dx[i];
                        by += dy[i];
                        moved = true;
                    }
                }
                if (board[rx][ry] != 'O') {
                    if (board[rx + dx[i]][ry + dy[i]] != '#' && (!(rx + dx[i] == bx && ry + dy[i] == by) || board[rx + dx[i]][ry + dy[i]] == 'O')) {
                        rx += dx[i];
                        ry += dy[i];
                        moved = true;
                    }
                }
                if (!moved) {
                    break;
                }
            }

            if (board[bx][by] == 'O') {
                continue;
            }

            if (board[rx][ry] == 'O') {
                std::cout << "1\n";
                return 0;
            }

            q.push({{{rx, ry}, {bx, by}}, count + 1});
        }
    }

    std::cout << "0\n";
    return 0;
}
