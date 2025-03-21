#include <iostream>

int N;
int forest[501][501];
int dp[501][501];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int move(int x, int y) {
    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
            continue;
        }

        if (forest[nx][ny] <= forest[x][y]) {
            continue;
        }

        dp[x][y] = std::max(dp[x][y], move(nx, ny));
    }

    dp[x][y]++;

    return dp[x][y];
}

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> forest[i][j];
            dp[i][j] = -1;
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            answer = std::max(move(i, j), answer);
        }
    }

    std::cout << answer << "\n";

    return 0;
}
