#include <iostream>

int N, M;
char map[1001][1001];
bool visited[1001][1001];
int parent[1000001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int find_parent(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = find_parent(parent[x]);
    }
}

int dfs(int x, int y) {
    int nx;
    int ny;
    if (map[x][y] == 'U') {
        nx = x + dx[0];
        ny = y + dy[0];
    } else if (map[x][y] == 'D') {
        nx = x + dx[1];
        ny = y + dy[1];
    } else if (map[x][y] == 'L') {
        nx = x + dx[2];
        ny = y + dy[2];
    } else {
        nx = x + dx[3];
        ny = y + dy[3];
    }
    if (visited[nx][ny]) {
        int p_cur = find_parent(x * M + y);
        int p_next = find_parent(nx * M + ny);

        if (p_cur < p_next) {
            parent[p_next] = p_cur;
            return p_cur;
        } else {
            parent[p_cur] = p_next;
            return p_next;
        }
    } else {
        visited[nx][ny] = true;
        int ret = dfs(nx, ny);
        parent[x * M + y] = ret;
        return ret;
    }
}

int main() {
    std::cin >> N >> M;

    std::string row;
    int p = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> row;
        for (int j = 0; j < M; j++) {
            map[i][j] = row[j];
            parent[p] = p;
            p++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                parent[i * M + j] = dfs(i, j);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N * M; i++) {
        if (parent[i] == i) {
            answer++;
        }
    }
    
    std::cout << answer << "\n";

    return 0;
}
