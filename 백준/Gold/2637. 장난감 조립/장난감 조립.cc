#include <iostream>
#include <vector>
#include <queue>

int N, M;
int X, Y, K;
bool isBase[101];
int inDegree[101];
std::vector<int> outDegree[101];
std::vector<std::pair<int, int>> needParts[101];
int finalCount[101];

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        std::cin >> X >> Y >> K;
        inDegree[X]++;
        outDegree[Y].push_back(X);
        needParts[X].push_back({Y, K});
    }

    std::vector<int> partsOrder;
    std::queue<int> q;
    for (int i = 1; i < N; i++) {
        if (inDegree[i] == 0) {
            isBase[i] = true;
            q.push(i);
            partsOrder.push_back(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < outDegree[cur].size(); i++) {
            int next = outDegree[cur][i];
            inDegree[next]--;
            if (inDegree[next] == 0) {
                q.push(next);
                partsOrder.push_back(next);
            }
        }
    }
    finalCount[N] = 1;
    while (!partsOrder.empty()) {
        int cur = partsOrder.back();
        partsOrder.pop_back();

        for (std::pair<int, int> p : needParts[cur]) {
            finalCount[p.first] += p.second * finalCount[cur];
        }
    }

    for (int i = 1; i < N; i++) {
        if (isBase[i]) {
            std::cout << i << " " << finalCount[i] << "\n";
        }
    }

    return 0;
}
