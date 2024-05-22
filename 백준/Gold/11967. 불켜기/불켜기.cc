#include <iostream>
#include <vector>
#include <queue>

#define PII std::pair<int, int>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N, M;
std::vector<PII > roomInfo[101][101];
bool lighted[101][101];
bool visited[101][101];

int main() {
    std::cin >> N >> M;

    int X, Y, A, B;
    for (int i = 0; i < M; i++) {
        std::cin >> X >> Y >> A >> B;

        roomInfo[X][Y].push_back({A, B});
    }

    int answer = 1;
    std::queue<PII > q;
    q.push({1, 1});
    visited[1][1] = true;
    lighted[1][1] = true;

    while (!q.empty()) {
        PII cur = q.front();
        q.pop();

        for (PII next: roomInfo[cur.first][cur.second]) {
            if (lighted[next.first][next.second]) {
                continue;
            }
            lighted[next.first][next.second] = true;

            for (int i = 0; i < 4; i++) {
                int nx = next.first + dx[i];
                int ny = next.second + dy[i];
                if (nx < 1 || nx > N || ny < 1 || ny > N) {
                    continue;
                }
                if (visited[nx][ny]) {
                    q.push({nx, ny});
                }
            }
            answer++;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > N) {
                continue;
            }
            if (visited[nx][ny] || !lighted[nx][ny]) {
                continue;
            }
            visited[nx][ny] = true;
            q.push({nx, ny});
        }

    }

    std::cout << answer << "\n";

    return 0;
}
