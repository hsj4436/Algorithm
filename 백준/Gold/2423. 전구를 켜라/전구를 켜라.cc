#include <iostream>
#include <queue>

int N, M;
char board[502][502];
int visited[502][502];

int main() {
    std::cin >> N >> M;

    std::string row;
    for (int i = 0; i < N; i++) {
        std::cin >> row;
        for (int j = 0; j < M; j++) {
            board[i][j] = row[j];
        }
    }

    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < M + 1; j++) {
            visited[i][j] = 987654321;
        }
    }

    /**
     *  {x, y}, {direction, changed}
     *  direction
     *  0 - from left top
     *  1 - from left bottom
     *  2 - from right bottom
     *  3 - from right top
     */
    std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>> q;
    visited[0][0] = 0;
    if (board[0][0] == '/') {
        visited[1][1] = 1;
        q.push({{1, 1}, {0, 1}});
    } else {
        visited[1][1] = 0;
        q.push({{1, 1}, {0, 0}});
    }

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int direction = q.front().second.first;
        int changed = q.front().second.second;
        q.pop();

        if (direction == 0) {
            int nx = x - 1;
            int ny = y;
            if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= M - 1) {
                if (board[nx][ny] == '/' && changed < visited[nx][ny + 1]) {
                    visited[nx][ny + 1] = changed;
                    q.push({{nx, ny + 1}, {1, changed}});
                }
                if (board[nx][ny] == '\\' && changed + 1 < visited[nx][ny + 1]){
                    visited[nx][ny + 1] = changed + 1;
                    q.push({{nx, ny + 1}, {1, changed + 1}});
                }
            }
            nx = x;
            ny = y;
            if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= M - 1) {
                if (board[nx][ny] == '/' && changed + 1 < visited[nx + 1][ny + 1]) {
                    visited[nx + 1][ny + 1] = changed + 1;
                    q.push({{nx + 1, ny + 1}, {0, changed + 1}});
                }
                if (board[nx][ny] == '\\' && changed < visited[nx + 1][ny + 1]){
                    visited[nx + 1][ny + 1] = changed;
                    q.push({{nx + 1, ny + 1}, {0, changed}});
                }
            }
            nx = x;
            ny = y - 1;
            if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= M - 1) {
                if (board[nx][ny] == '/' && changed < visited[nx + 1][ny]) {
                    visited[nx + 1][ny] = changed;
                    q.push({{nx + 1, ny}, {3, changed}});
                }
                if (board[nx][ny] == '\\' && changed + 1 < visited[nx + 1][ny]){
                    visited[nx + 1][ny] = changed + 1;
                    q.push({{nx + 1, ny}, {3, changed + 1}});
                }
            }
        } else if (direction == 1) {
            int nx = x - 1;
            int ny = y - 1;
            if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= M - 1) {
                if (board[nx][ny] == '/' && changed + 1 < visited[nx][ny]) {
                    visited[nx][ny] = changed + 1;
                    q.push({{nx, ny}, {2, changed + 1}});
                }
                if (board[nx][ny] == '\\' && changed < visited[nx][ny]){
                    visited[nx][ny] = changed;
                    q.push({{nx, ny}, {2, changed}});
                }
            }
            nx = x - 1;
            ny = y;
            if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= M - 1) {
                if (board[nx][ny] == '/' && changed < visited[nx][ny + 1]) {
                    visited[nx][ny + 1] = changed;
                    q.push({{nx, ny + 1}, {1, changed}});
                }
                if (board[nx][ny] == '\\' && changed + 1 < visited[nx][ny + 1]){
                    visited[nx][ny + 1] = changed + 1;
                    q.push({{nx, ny + 1}, {1, changed + 1}});
                }
            }
            nx = x;
            ny = y;
            if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= M - 1) {
                if (board[nx][ny] == '/' && changed + 1 < visited[nx + 1][ny + 1]) {
                    visited[nx + 1][ny + 1] = changed + 1;
                    q.push({{nx + 1, ny + 1}, {0, changed + 1}});
                }
                if (board[nx][ny] == '\\' && changed < visited[nx + 1][ny + 1]){
                    visited[nx + 1][ny + 1] = changed;
                    q.push({{nx + 1, ny + 1}, {0, changed}});
                }
            }
        } else if (direction == 2) {
            int nx = x;
            int ny = y - 1;
            if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= M - 1) {
                if (board[nx][ny] == '/' && changed < visited[nx + 1][ny]) {
                    visited[nx + 1][ny] = changed;
                    q.push({{nx + 1, ny}, {3, changed}});
                }
                if (board[nx][ny] == '\\' && changed + 1 < visited[nx + 1][ny]){
                    visited[nx + 1][ny] = changed + 1;
                    q.push({{nx + 1, ny}, {3, changed + 1}});
                }
            }
            nx = x - 1;
            ny = y - 1;
            if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= M - 1) {
                if (board[nx][ny] == '/' && changed + 1 < visited[nx][ny]) {
                    visited[nx][ny] = changed + 1;
                    q.push({{nx, ny}, {2, changed + 1}});
                }
                if (board[nx][ny] == '\\' && changed < visited[nx][ny]){
                    visited[nx][ny] = changed;
                    q.push({{nx, ny}, {2, changed}});
                }
            }
            nx = x - 1;
            ny = y;
            if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= M - 1) {
                if (board[nx][ny] == '/' && changed < visited[nx][ny + 1]) {
                    visited[nx][ny + 1] = changed;
                    q.push({{nx, ny + 1}, {1, changed}});
                }
                if (board[nx][ny] == '\\' && changed + 1 < visited[nx][ny + 1]){
                    visited[nx][ny + 1] = changed + 1;
                    q.push({{nx, ny + 1}, {1, changed + 1}});
                }
            }
        } else {
            int nx = x - 1;
            int ny = y - 1;
            if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= M - 1) {
                if (board[nx][ny] == '/' && changed + 1 < visited[nx][ny]) {
                    visited[nx][ny] = changed + 1;
                    q.push({{nx, ny}, {2, changed + 1}});
                }
                if (board[nx][ny] == '\\' && changed < visited[nx][ny]){
                    visited[nx][ny] = changed;
                    q.push({{nx, ny}, {2, changed}});
                }
            }
            nx = x;
            ny = y - 1;
            if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= M - 1) {
                if (board[nx][ny] == '/' && changed < visited[nx + 1][ny]) {
                    visited[nx + 1][ny] = changed;
                    q.push({{nx + 1, ny}, {3, changed}});
                }
                if (board[nx][ny] == '\\' && changed + 1 < visited[nx + 1][ny]){
                    visited[nx + 1][ny] = changed + 1;
                    q.push({{nx + 1, ny}, {3, changed + 1}});
                }
            }
            nx = x;
            ny = y;
            if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= M - 1) {
                if (board[nx][ny] == '/' && changed + 1 < visited[nx + 1][ny + 1]) {
                    visited[nx + 1][ny + 1] = changed + 1;
                    q.push({{nx + 1, ny + 1}, {0, changed + 1}});
                }
                if (board[nx][ny] == '\\' && changed < visited[nx + 1][ny + 1]){
                    visited[nx + 1][ny + 1] = changed;
                    q.push({{nx + 1, ny + 1}, {0, changed}});
                }
            }
        }
    }

    if (visited[N][M] == 987654321) {
        std::cout << "NO SOLUTION\n";
    } else {
        std::cout << visited[N][M] << "\n";
    }
    return 0;
}
