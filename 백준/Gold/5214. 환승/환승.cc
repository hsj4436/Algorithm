#include <iostream>
#include <vector>
#include <queue>

int N, K, M;
std::vector<int> tubeAtStations[100001];
std::vector<int> hyperTubes[100001];
bool visited[100001];

int main() {
    std::cin >> N >> K >> M;

    for (int i = 1; i < M + 1; i++) {
        int station;
        for (int j = 0; j < K; j++) {
            std::cin >> station;
            tubeAtStations[station].push_back(i);
            hyperTubes[i].push_back(station);
        }
    }
    
    if (N == 1) {
        std::cout << 1 << "\n";
        return 0;
    }

    std::queue<std::pair<int, int>> q;
    q.push({1, 1});
    visited[1] = true;

    while (!q.empty()) {
        int usedTubes = q.front().first;
        int currentStation = q.front().second;
        q.pop();

        for (int nextTube : tubeAtStations[currentStation]) {
            for (int nextStation : hyperTubes[nextTube]) {
                if (!visited[nextStation]) {
                    if (nextStation == N) {
                        std::cout << usedTubes + 1 << "\n";
                        return 0;
                    } else {
                        visited[nextStation] = true;
                        q.push({usedTubes + 1, nextStation});
                    }
                }
            }
        }
    }

    std::cout << -1 << "\n";

    return 0;
}
