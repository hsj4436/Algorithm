#include <iostream>
#include <vector>
#include <cstring>

int T, N, M;
int a, b;
std::vector<int> candidates[1001];
int selected[1001];
bool done[1001];

bool dfs(int x) {
    for (auto candidate : candidates[x]) {
        if (done[candidate]) {
            continue;
        }
        done[candidate] = true;
        if (selected[candidate] == 0 || dfs(selected[candidate])) {
            selected[candidate] = x;
            return true;
        }
    }
    return false;
}

int main() {
    std::cin >> T;

    for (int tc = 0; tc < T; tc++) {
        std::cin >> N >> M;
        std::memset(selected, 0, sizeof(selected));
        for (int i = 1; i < 1001; i++) {
            candidates[i].clear();
        }
        for (int i = 0; i < M; i++) {
            std::cin >> a >> b;
            for (int j = a; j < b + 1; j++) {
                candidates[i + 1].push_back(j);
            }
        }

        int answer = 0;
        for (int i = 1; i < M + 1; i++) {
            std::memset(done, false, sizeof(done));
            if (dfs(i)) {
                answer++;
            }
        }
        std::cout << answer << "\n";
    }
    return 0;
}
