#include <iostream>
#include <vector>

int N, M;
int X;
std::vector<int> edge[100001];
bool visited[100001];
int answer = 0;

void dfs(int cur) {
    for (int next : edge[cur]) {
        if (visited[next]) {
            continue;
        }
        visited[next] = true;
        dfs(next);
        answer++;
    }
}

int main() {
    std::cin >> N >> M;

    int A, B;
    for (int i = 0; i < M; i++) {
        std::cin >> A >> B;
        edge[B].push_back(A);
    }
    std::cin >> X;

    visited[X] = true;
    dfs(X);

    std::cout << answer << "\n";

    return 0;
}
