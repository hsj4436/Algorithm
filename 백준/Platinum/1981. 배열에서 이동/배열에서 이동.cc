#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define PII std::pair<int, int>

int N;
int arr[101][101];
bool visited[101][101];
int max_n = 0, min_n = 201;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool bfs(int mid) {
    for (int i = min_n; i < max_n + 1; i++) {
        std::memset(visited, true, sizeof(visited));
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (i <= arr[j][k] && arr[j][k] <= i + mid) {
                    visited[j][k] = false;
                }
            }
        }
        
        if (visited[0][0]) {
            continue;
        }
        
        std::queue<PII> q;
        q.push({0, 0});
        visited[0][0] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == N - 1 && y == N - 1) {
                return true;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
                    continue;
                }

                if (visited[nx][ny]) {
                    continue;
                }

                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return false;
}

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> arr[i][j];
            max_n = std::max(max_n, arr[i][j]);
            min_n = std::min(min_n, arr[i][j]);
        }
    }

    int left = 0, right = max_n - min_n;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (bfs(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    std::cout << right + 1 << "\n";

    return 0;
}