#include <iostream>
#include <vector>

#define INF 50000000001
#define LL long long
#define PLL std::pair<LL, LL>

int C, E, D;
int N;
std::vector<PLL> gas_stations;
LL dp[1002][501];

int main() {
    std::cin >> C >> E >> D;

    std::cin >> N;

    gas_stations.resize(N + 1);
    gas_stations[0] = {0, 0};

    LL total_distance = 0;
    LL distance = 0;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> distance;
        total_distance += distance;
        gas_stations[i].first = total_distance;
    }

    for (int i = 1; i < N + 1; i++) {
        std::cin >> gas_stations[i].second;
    }

    for (int i = 0; i < C + 1; i++) {
        dp[0][i] = 0L;
    }
    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < C + 1; j++) {
            dp[i][j] = INF;
        }
    }

    for (int i = 1; i < N + 1; i++) {
        LL d = gas_stations[i].first - gas_stations[i - 1].first;
        for (int j = 0; j < C + 1; j++) {
            for (int k = d * E; k < C + 1; k++) {
                LL last_gas = k - E * d;
                LL last_paid = dp[i - 1][k];
                if (last_gas + j > C) {
                    last_paid += gas_stations[i].second * (C - last_gas);
                    last_gas = C;
                } else {
                    last_paid += gas_stations[i].second * j;
                    last_gas += j;
                }
                if (last_paid < dp[i][last_gas]) {
                    dp[i][last_gas] = last_paid;
                }
            }
        }
    }

    LL ans = INF;
    LL d = D - gas_stations[N].first;
    for (int i = d * E; i < C + 1; i++) {
        ans = std::min(ans, dp[N][i]);
    }

    if (ans == INF) {
        std::cout << "-1\n";
    } else {
        std::cout << ans << "\n";
    }

    return 0;
}
