#include <iostream>
#include <queue>

#define INF 987654321

int N, M, K;
int map[1001][1001];
int visited[1001][1001][11];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct state {
    int x;
    int y;
    int dist;
    int k;
    state() {}
    state(int x, int y, int dist, int k) : x(x), y(y), dist(dist), k(k) {}
};

int main() {
    std::cin >> N >> M >> K;

    for (int i = 1; i < N + 1; i++) {
        std::string row;
        std::cin >> row;
        for (int j = 1; j < M + 1; j++) {
            map[i][j] = row[j - 1] - '0';
            for (int k = 0; k < K + 1; k++) {
                visited[i][j][k] = INF;
            }
        }
    }

    std::queue<state> trace;
    for (int i = 0; i < K + 1; i++) {
        visited[1][1][i] = 1;
    }
    trace.push(state(1, 1, 1, 0));

    while (!trace.empty()) {
        state cur = trace.front();
        trace.pop();

        if (cur.x == N && cur.y == M) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > M) {
                continue;
            }

            if (map[nx][ny] == 0) {
                if (cur.dist + 1 < visited[nx][ny][cur.k]) {
                    visited[nx][ny][cur.k] = cur.dist + 1;
                    trace.push(state(nx, ny, cur.dist + 1, cur.k));
                }
            } else {
                if (cur.k < K) {
                    if (cur.dist + 1 < visited[nx][ny][cur.k + 1]) {
                        visited[nx][ny][cur.k + 1] = cur.dist + 1;
                        trace.push(state(nx, ny, cur.dist + 1, cur.k + 1));
                    }
                }
            }
        }
    }

    int answer = INF;
    for (int i = 0; i < K + 1; i++) {
        answer = std::min(answer, visited[N][M][i]);
    }
    std::cout << (answer == INF ? -1 : answer) << "\n";
    return 0;
}
