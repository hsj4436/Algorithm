#include <iostream>
#include <queue>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int R, C;
int hX, hY;
int grid[1001][1001];
bool isLighted[1001][1001];

int main() {
    std::cin >> R >> C;

    std::string row;
    for (int i = 0; i < R; i++) {
        std::cin >> row;
        for (int j = 0; j < C; j++) {
            isLighted[i][j] = false;
            grid[i][j] = row[j] - 'a';
        }
    }

    std::cin >> hX >> hY;
    hX--;
    hY--;

    std::string command;
    std::cin >> command;
    for (char c : command) {
        if (c == 'U') {
            hX += dx[0];
            hY += dy[0];
        } else if (c == 'D') {
            hX += dx[2];
            hY += dy[2];
        } else if (c == 'L') {
            hX += dx[1];
            hY += dy[1];
        } else if (c == 'R') {
            hX += dx[3];
            hY += dy[3];
        } else {
            if (isLighted[hX][hY]) {
                continue;
            }

            std::queue<std::pair<int, int>> q;
            q.push({hX, hY});
            isLighted[hX][hY] = true;

            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1) {
                        continue;
                    }
                    if (grid[nx][ny] != grid[hX][hY] || isLighted[nx][ny]) {
                        continue;
                    }
                    isLighted[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    isLighted[hX][hY] = true;
    for (int i = 0; i < 4; i++) {
        int nx = hX + dx[i];
        int ny = hY + dy[i];
        if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1) {
            continue;
        }
        isLighted[nx][ny] = true;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (isLighted[i][j]) {
                std::cout << ".";
            } else {
                std::cout << "#";
            }
        }
        std::cout << "\n";
    }

    return 0;
}