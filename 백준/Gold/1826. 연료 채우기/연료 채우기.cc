#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N;
int a, b;
int L, P;
std::vector<std::pair<int, int>> gas_stations;
std::priority_queue<int> pq;

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> a >> b;
        gas_stations.push_back({a, b});
    }

    std::sort(gas_stations.begin(), gas_stations.end());

    std::cin >> L >> P;

    int i = 0, answer = 0;
    bool possible = true;
    while (P < L) {
        while (i < N && P >= gas_stations[i].first) {
            pq.push(gas_stations[i].second);
            i++;
        }

        if (pq.empty()) {
            possible = false;
            break;
        }

        P += pq.top();
        pq.pop();
        answer++;
    }

    std::cout << (possible ? answer : -1) << "\n";
    return 0;
}
