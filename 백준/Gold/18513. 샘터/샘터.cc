#include <iostream>
#include <queue>
#include <map>

int dx[2] = {-1, 1};

int N, K;
std::map<int, int> visited;

int main() {
    std::cin >> N >> K;

    std::queue<int> q;

    int lake;
    for (int i = 0; i < N; i++) {
        std::cin >> lake;
        visited[lake] = 0;
        q.push(lake);
    }

    long long answer = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (K == 0) {
            break;
        }

        for (int i = 0; i < 2; i++) {
            int nx = cur + dx[i];
            int nd = visited[cur] + 1;

            if (visited.find(nx) == visited.end()) {
                answer += nd;
                visited[nx] = nd;
                q.push(nx);
                K--;
            }
            if (K == 0) {
                break;
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}
