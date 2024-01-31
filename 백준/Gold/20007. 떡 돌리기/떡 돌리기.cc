#include <iostream>
#include <queue>

int N, M, X, Y;
int A, B, C;
int dist[1001][1001];

int main() {
    std::cin >> N >> M >> X >> Y;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = 10001;
        }
    }

    for (int i = 0; i < M; i++) {
        std::cin >> A >> B >> C;
        dist[A][B] = C;
        dist[B][A] = C;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (i == k) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                if (i == j || j == k) {
                    continue;
                }
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    std::priority_queue<std::pair<int, int>> pq;
    for (int i = 0; i < N; i++) {
        if (i == Y) {
            continue;
        }
        if (dist[Y][i] > X || dist[i][Y] + dist[Y][i] > X) {
            std::cout << "-1\n";
            return 0;
        }
        pq.push({-dist[Y][i], i});
    }

    int day = 0;
    while (!pq.empty()) {
        int sum = 0;
        while (!pq.empty()) {
            int d = -pq.top().first;
            int house = pq.top().second;
            if (sum + d + dist[house][Y] <= X) {
                sum += d + dist[house][Y];
                pq.pop();
            } else {
                break;
            }
        }
        day++;
    }

    std::cout << day << "\n";

    return 0;
}