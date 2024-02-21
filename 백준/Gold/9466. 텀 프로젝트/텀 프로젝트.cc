#include <iostream>
#include <cstring>
#include <vector>

int T, N;
int selected[100001];
bool visited[100001];
bool done[100001];
int matched = 0;

void dfs(int cur) {
    visited[cur] = true;

    if (!visited[selected[cur]]) {
        dfs(selected[cur]);
    } else if (!done[selected[cur]]) {
        for (int i = selected[cur]; i != cur; i = selected[i]) {
            matched++;
        }
        matched++;
    }
    done[cur] = true;
}

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> T;

    while (T--) {
        std::cin >> N;

        for (int i = 1; i < N + 1; i++) {
            std::cin >> selected[i];
        }

        for (int i = 1; i < N + 1; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        std::cout << N - matched << "\n";
        matched = 0;
        std::memset(visited, false, sizeof(visited));
        std::memset(done, false, sizeof(done));
    }
}