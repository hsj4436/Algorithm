#include <iostream>
#include <queue>

int N, M;
char campus[601][601];
bool visited[601][601];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    std::cin >> N >> M;

    int start_x = 0, start_y = 0;
    for (int i = 0; i < N; i++) {
        std::string row;
        std::cin >> row;
        for (int j = 0; j < M; j++) {
            campus[i][j] = row[j];
            if (row[j] == 'I') {
                start_x = i;
                start_y = j;
            }
        }
    }

    int answer = 0;
    std::queue<std::pair<int, int>> trace;
    trace.push({start_x, start_y});
    visited[start_x][start_y] = true;

    while (!trace.empty()) {
        auto current = trace.front();
        trace.pop();

        if (campus[current.first][current.second] == 'P') {
            answer++;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];

            if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
                continue;
            }

            if (campus[nx][ny] == 'X') {
                continue;
            }

            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                trace.push({nx, ny});
            }
        }
    }

    if (answer == 0) {
        std::cout << "TT\n";
    } else {
        std::cout << answer << "\n";
    }

    return 0;
}
