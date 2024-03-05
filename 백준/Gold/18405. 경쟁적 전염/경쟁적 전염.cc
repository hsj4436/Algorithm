#include <iostream>
#include <queue>

#define PII std::pair<int, int>

int dx[4] = {-1, 0, 1, 0};

int dy[4] = {0, -1, 0, 1};
int N, K;

int S, X, Y;
int lab[201][201];

struct cmp {
    bool operator() (std::pair<int, PII> a, std::pair<int, PII> b) {
        if (a.first == b.first) {
            return lab[a.second.first][a.second.second] > lab[b.second.first][b.second.second];
        } else {
            return a.first > b.first;
        }
    }
};

int main() {
    std::cin >> N >> K;

    std::priority_queue<std::pair<int, PII>, std::vector<std::pair<int, PII>>, cmp> pq;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            std::cin >> lab[i][j];
            if (lab[i][j] > 0) {
                pq.push({1, {i, j}});
            }
        }
    }

    std::cin >> S >> X >> Y;

    while (!pq.empty()) {
        int t = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (t == S + 1) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > N) {
                continue;
            }
            if (lab[nx][ny] != 0) {
                continue;
            }
            lab[nx][ny] = lab[x][y];
            pq.push({t + 1, {nx, ny}});
        }
    }


    std::cout << lab[X][Y] << "\n";

    return 0;
}
