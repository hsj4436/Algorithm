#include <iostream>
#include <queue>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N, K;
int S, X, Y;
std::pair<int, int> lab[201][201];

int main() {
    std::cin >> N >> K;

    int cell;
    std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            std::cin >> cell;
            if (cell != 0) {
                lab[i][j] = {cell, 0};
            }
        }
    }

    std::cin >> S >> X >> Y;

    for (int i = 0; i < S; i++) {
        for (int j = 1; j < N + 1; j++) {
            for (int k = 1; k < N + 1; k++) {
                if (lab[j][k].second == i && lab[j][k].first != 0) {
                    pq.push({-lab[j][k].first, {j, k}});
                }
            }
        }
        while (!pq.empty()) {
            int v = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx < 1 || nx > N || ny < 1 || ny > N) {
                    continue;
                }
                if (lab[nx][ny].first != 0) {
                    continue;
                }
                lab[nx][ny] = {v, i + 1};
            }
        }
    }

    std::cout << lab[X][Y].first << "\n";

    return 0;
}
