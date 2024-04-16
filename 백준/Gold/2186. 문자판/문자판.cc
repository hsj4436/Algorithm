#include <iostream>

int N, M, K;
std::string word;
char grid[101][101];
int dp[101][101][81];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int dfs(int x, int y, int index) {
    if (index == word.size() - 1) {
        return dp[x][y][index] = 1;
    }

    if (dp[x][y][index] != -1) {
        return dp[x][y][index];
    }

    dp[x][y][index] = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < K + 1; j++) {
            int nx = x + dx[i] * j;
            int ny = y + dy[i] * j;

            if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
                break;
            }
            if (word[index + 1] == grid[nx][ny]) {
                dp[x][y][index] += dfs(nx, ny, index + 1);
            }
        }
    }

    return dp[x][y][index];
}

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> M >> K;

    std::string row;
    for (int i = 0; i < N; i++) {
        std::cin >> row;
        for (int j = 0; j < M; j++) {
            grid[i][j] = row[j];
        }
    }

    std::cin >> word;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < word.size(); k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == word[0]) {
                answer += dfs(i, j, 0);
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}
