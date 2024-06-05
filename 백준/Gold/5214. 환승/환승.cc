#include <iostream>
#include <vector>
#include <queue>

int N, K, M;
std::vector<int> stations[101001];
int distance[101001];

int main() {
    std::cin >> N >> K >> M;

    for (int i = 1; i < M + 1; i++) {
        int station;
        for (int j = 0; j < K; j++) {
            std::cin >> station;
            stations[station].push_back(i + N);
            stations[i + N].push_back(station);
        }
    }

    if (N == 1) {
        std::cout << 1 << "\n";
        return 0;
    }

    std::fill_n(&distance[0], 101001, 200000);

    std::queue<std::pair<int, int>> q;
    q.push({1, 1});
    distance[1] = 1;

    while (!q.empty()) {
        int passedStations = q.front().first;
        int currentStation = q.front().second;
        q.pop();

        for (int next : stations[currentStation]) {
            if (next > N && passedStations < distance[next]) {
                distance[next] = passedStations;
                q.push({passedStations, next});
            } else if (next <= N && passedStations + 1 < distance[next]){
                distance[next] = passedStations + 1;
                q.push({passedStations + 1, next});
            }
        }
    }

    if (distance[N] == 200000) {
        std::cout << -1 << "\n";
    } else {
        std::cout << distance[N] << "\n";
    }

    return 0;
}
