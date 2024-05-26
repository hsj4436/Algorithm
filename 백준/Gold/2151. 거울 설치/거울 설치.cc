#include <iostream>
#include <queue>

#define INF 987654321
#define PII std::pair<int, int>

struct state {
    PII cur;
    int direction;
    int installed;
    state() {}
    state(PII cur, int direction, int installed) : cur(cur), direction(direction), installed(installed) {}
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N;
char home[51][51];
int visited[51][51][4];

int main() {
    std::cin >> N;

    PII start;
    std::string row;
    for (int i = 0; i < N; i++) {
        std::cin >> row;
        for (int j = 0; j < N; j++) {
            home[i][j] = row[j];
            if (row[j] == '#') {
                start = {i, j};
            }
        }
    }

    std::queue<state> q;
    for (int i = 0; i < 4; i++) {
        int nx = start.first + dx[i];
        int ny = start.second + dy[i];
        if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
            continue;
        }
        if (home[nx][ny] != '*') {
            q.push(state(start, i, 0));
        }
    }

    std::fill_n(&visited[0][0][0], 51 * 51 * 4, INF);

    home[start.first][start.second] = '.';
    visited[start.first][start.second][0] = 0;
    visited[start.first][start.second][1] = 0;
    visited[start.first][start.second][2] = 0;
    visited[start.first][start.second][3] = 0;

    int answer = INF;
    while (!q.empty()) {
        state now = q.front();
        q.pop();

        int x = now.cur.first;
        int y = now.cur.second;

        if (home[x][y] == '#') {
            answer = std::min(answer, now.installed);
            continue;
        }

        if (home[x][y] == '.') {
            int nx = x + dx[now.direction];
            int ny = y + dy[now.direction];
            if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
                continue;
            }
            if (home[nx][ny] == '*') {
                continue;
            }
            if (visited[nx][ny][now.direction] < now.installed) {
                continue;
            }
            visited[nx][ny][now.direction] = now.installed;
            q.push(state({nx, ny}, now.direction, now.installed));
        } else if (home[x][y] = '!') {
            int nx = x + dx[now.direction];
            int ny = y + dy[now.direction];
            if (!(nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) && home[nx][ny] != '*' && visited[nx][ny][now.direction] >= now.installed) {
                visited[nx][ny][now.direction] = now.installed;
                q.push(state({nx, ny}, now.direction, now.installed));
            }

            int nd = (now.direction + 1) % 4;
            nx = x + dx[nd];
            ny = y + dy[nd];
            if (!(nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) && home[nx][ny] != '*' && visited[nx][ny][nd] >= now.installed + 1) {
                visited[nx][ny][nd] = now.installed + 1;
                q.push(state({nx, ny}, nd, now.installed + 1));
            }

            nd = (now.direction - 1 + 4) % 4;
            nx = x + dx[nd];
            ny = y + dy[nd];
            if (!(nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) && home[nx][ny] != '*' && visited[nx][ny][nd] >= now.installed + 1) {
                visited[nx][ny][nd] = now.installed + 1;
                q.push(state({nx, ny}, nd, now.installed + 1));
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}
