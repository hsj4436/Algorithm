#include <iostream>

#define INF 1000000

int T;
int N, M;
int adj[101][101];
int A, B, C;
int K;
int friends[101];

int main() {
    std::cin >> T;

    while (T--) {
        std::cin >> N >> M;

        std::fill_n(&adj[0][0], 101 * 101, INF);

        for (int i = 0; i < M; i++) {
            std::cin >> A >> B >> C;
            adj[A][B] = C;
            adj[B][A] = C;
        }

        std::cin >> K;
        for (int i = 0; i < K; i++) {
            std::cin >> friends[i];
        }

        for (int k = 1; k < N + 1; k++) {
            for (int i = 1; i < N + 1; i++) {
                if (i == k) {
                    continue;
                }
                for (int j = 1; j < N + 1; j++) {
                    if (i == j || j == k) {
                        continue;
                    }
                    adj[i][j] = std::min(adj[i][k] + adj[k][j], adj[i][j]);
                }
            }
        }
        
        for (int i = 1; i < N + 1; i++) {
            adj[i][i] = 0;
        }

        int minDistanceSum = K * INF, minRoomNumber = INF;
        for (int i = 1; i < N + 1; i++) {
            int sum = 0;
            for (int j = 0; j < K; j++) {
                sum += adj[friends[j]][i];
            }
            if (sum < minDistanceSum) {
                minDistanceSum = sum;
                minRoomNumber = i;
            }
        }
        std::cout << minRoomNumber << "\n";
    }

    return 0;
}
