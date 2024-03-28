#include <iostream>
#include <vector>
#include <queue>

int N, M;
int X, Y, K;
bool isBase[101];
int inDegree[101];
std::vector<std::pair<int, int>> outDegree[101];
int finalCount[101];

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        std::cin >> X >> Y >> K;
        inDegree[Y]++;
        outDegree[X].push_back({Y, K});
    }

    finalCount[N] = 1;
    std::queue<int> q;
    q.push(N);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (outDegree[cur].empty()) {
            isBase[cur] = true;
            continue;
        }

        for (int i = 0; i < outDegree[cur].size(); i++) {
            int next = outDegree[cur][i].first;
            int count = outDegree[cur][i].second;
            finalCount[next] += finalCount[cur] * count;
            inDegree[next]--;
            if (inDegree[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 1; i < N; i++) {
        if (isBase[i]) {
            std::cout << i << " " << finalCount[i] << "\n";
        }
    }

    return 0;
}
