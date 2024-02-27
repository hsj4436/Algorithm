#include <iostream>
#include <queue>

#define PII std::pair<int, int>

int dx[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[8] = {0, -1, 0, 1, 1, -1, 1, -1};

int N, M;
int farm[101][71];
bool visited[101][71];
int answer = 0;

bool is_top(int x, int y) {
    bool visited_copy[101][71];
    std::fill(&visited_copy[0][0], &visited_copy[100][71], false);
    int height = farm[x][y];
    std::queue<PII> q;
    visited_copy[x][y] = true;
    q.push({x, y});

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
                continue;
            }

            if (visited_copy[nx][ny]) {
                continue;
            }

            if (farm[nx][ny] > height) {
                return false;
            }
            if (farm[nx][ny] == height) {
                visited_copy[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return true;
}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> farm[i][j];
        }
    }

    std::queue<PII> q;
    q.push({0, 0});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (visited[x][y]) {
            continue;
        }
        visited[x][y] = true;

        if (is_top(x, y)) {
            answer++;
            int height = farm[x][y];
            std::queue<PII> top_q;
            top_q.push({x, y});
            visited[x][y] = false;
            while (!top_q.empty()) {
                int cur_x = top_q.front().first;
                int cur_y = top_q.front().second;
                top_q.pop();

                if (visited[cur_x][cur_y]) {
                    continue;
                }
                visited[cur_x][cur_y] = true;

                for (int i = 0; i < 8; i++) {
                    int nx = cur_x + dx[i];
                    int ny = cur_y + dy[i];

                    if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
                        continue;
                    }

                    if (visited[nx][ny]) {
                        continue;
                    }

                    if (farm[nx][ny] == height) {
                        top_q.push({nx, ny});
                    } else if (farm[nx][ny] < height) {
                        q.push({nx, ny});
                    }
                }
            }
        } else {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
                    continue;
                }

                if (visited[nx][ny]) {
                    continue;
                }

                q.push({nx, ny});
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}