#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

bool user[101][101];
int dist[101][101];

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::fill(&dist[0][0], &dist[n + 1][n + 1], 5001);

    for(int i = 0; i < m; i++){
        int a = 0, b = 0;
        std::cin >> a >> b;
        user[a][b] = true;
        user[b][a] = true;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for (int k = 1; k < n + 1; k++) {
        for (int i = 1; i < n + 1; i++) {
            if (i == k) {
                continue;
            }
            for (int j = 1; j < n + 1; j++) {
                if (i == j || j == k) {
                    continue;
                }
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int min_kevin = 5001;
    int ans = 0;
    for (int i = 1; i < n + 1; i++) {
        int sum = 0;
        for (int j = 1; j < n + 1; j++) {
            if (i == j || dist[i][j] >= 5001) {
                continue;
            }
            sum += dist[i][j];
        }
        if (sum < min_kevin) {
            min_kevin = sum;
            ans = i;
        }
    }

    std::cout << ans << "\n";
    return 0;
}
