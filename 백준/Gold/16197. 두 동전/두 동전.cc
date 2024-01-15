#include <iostream>
#include <vector>
#include <queue>

int N, M;
char board[21][21];

struct coin {
    int x1;
    int y1;
    int x2;
    int y2;
    coin(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int main() {
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> coins;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> board[i][j];
            if (board[i][j] == 'o') {
                coins.push_back({i, j});
                board[i][j] = '.';
            }
        }
    }

    std::queue<std::pair<coin, int>> q;
    coin c = coin(coins[0].first, coins[0].second, coins[1].first, coins[1].second);
    q.push({c, 0});
    while (!q.empty()) {
        coin current = q.front().first;
        int count = q.front().second;
        q.pop();

        if (count == 11) {
            std::cout << "-1\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx1 = current.x1 + dx[i];
            int ny1 = current.y1 + dy[i];
            int nx2 = current.x2 + dx[i];
            int ny2 = current.y2 + dy[i];

            bool c1_dropped = (nx1 < 0 || nx1 > N - 1 || ny1 < 0 || ny1 > M - 1);
            bool c2_dropped = (nx2 < 0 || nx2 > N - 1 || ny2 < 0 || ny2 > M - 1);

            if (c1_dropped && c2_dropped) {
                continue;
            }
            if ((c1_dropped || c2_dropped) && count + 1 <= 10) {
                std::cout << count + 1 << "\n";
                return 0;
            }
            if (board[nx1][ny1] == '#') {
                nx1 = current.x1;
                ny1 = current.y1;
            }
            if (board[nx2][ny2] == '#') {
                nx2 = current.x2;
                ny2 = current.y2;
            }
            q.push({coin(nx1, ny1, nx2, ny2), count + 1});
        }
    }
    return 0;
}
