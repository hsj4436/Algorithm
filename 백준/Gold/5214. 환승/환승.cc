#include <iostream>
#include <vector>
#include <set>
#include <queue>

int N, K, M;
std::set<int> tubeAtStations[100001];
std::vector<int> hyperTubes[100001];
int distance[100001];

int main() {
    std::cin >> N >> K >> M;

    for (int i = 1; i < M + 1; i++) {
        int station;
        for (int j = 0; j < K; j++) {
            std::cin >> station;
            tubeAtStations[station].insert(i);
            hyperTubes[i].push_back(station);
        }
    }

    std::fill_n(&distance[0], 100001, 100001);

    std::queue<std::pair<int, int>> q;
    q.push({1, 1});
    distance[1] = 1;

    while (!q.empty()) {
        int usedTubes = q.front().first;
        int currentStation = q.front().second;
        q.pop();

        if (usedTubes > distance[currentStation]) {
            continue;
        }
        
        for (int nextTube : tubeAtStations[currentStation]) {
            for (int nextStation : hyperTubes[nextTube]) {
                if (usedTubes + 1 < distance[nextStation]) {
                    distance[nextStation] = usedTubes + 1;
                    q.push({usedTubes + 1, nextStation});
                }
            }
        }
    }


    if (distance[N] == 100001) {
        std::cout << -1 << "\n";
    } else {
        std::cout << distance[N] << "\n";
    }

    return 0;
}
