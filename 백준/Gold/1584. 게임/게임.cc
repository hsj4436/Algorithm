#include <iostream>
#include <queue>

#define PII std::pair<int, int>

int N;
int X1, Y1, X2, Y2;
int M;
int cell[502][502] = {{0, }, };
bool visited[502][502];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> X1 >> Y1 >> X2 >> Y2;
        if (X1 > X2) {
            std::swap(X1, X2);
        }
        if (Y1 > Y2) {
            std::swap(Y1, Y2);
        }
        for (int j = X1; j < X2 + 1; j++) {
            for (int k = Y1; k < Y2 + 1; k++) {
                cell[j][k] = 1;
            }
        }
    }

    std::cin >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> X1 >> Y1 >> X2 >> Y2;
        if (X1 > X2) {
            std::swap(X1, X2);
        }
        if (Y1 > Y2) {
            std::swap(Y1, Y2);
        }
        for (int j = X1; j < X2 + 1; j++) {
            for (int k = Y1; k < Y2 + 1; k++) {
                visited[j][k] = true;
            }
        }
    }

    std::deque<std::pair<int, PII>> q;
    q.push_back({0, {0, 0}});
    visited[0][0] = true;

    while (!q.empty()) {
        int lost = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop_front();

        if (x == 500 && y == 500) {
            std::cout << lost << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx > 500 || ny < 0 || ny > 500) {
                continue;
            }

            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                if (cell[nx][ny] == 1) {
                    q.push_back({lost + 1, {nx, ny}});
                } else {
                    q.push_front({lost, {nx, ny}});
                }
            }
        }
    }

    std::cout << "-1\n";

    return 0;
}