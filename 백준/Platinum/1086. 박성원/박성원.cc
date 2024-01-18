#include <iostream>
#include <algorithm>

int N;
std::string set[16];
int K;
long long dp[1 << 16][101];
int cache[51];
int cache_str[16];

int MOD(std::string a, int b) {
    int res = 0;
    for (int i = 0; i < a.length(); i++) {
        res = (res * 10 + a[i] - '0') % b;
    }

    return res;
}

long long GCD(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a % b);
    }
}

void sol() {
    for (int cur = 0; cur < (1 << N); cur++) {
        for (int i = 0; i < N; i++) {
            if ((cur & (1 << i)) == 0) {
                int next_state = cur | (1 << i);
                for (int j = 0; j < K; j++) {
                    int next_K = ((j * cache[set[i].length()]) % K + cache_str[i]) % K;
                    dp[next_state][next_K] += dp[cur][j];
                }
            }
        }
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> set[i];
    }

    std::cin >> K;

    dp[0][0] = 1;

    cache[0] = 1 % K;

    for (int i = 1; i < 51; i++) {
        cache[i] = (cache[i - 1] * 10) % K;
    }

    for (int i = 0; i < N; i++) {
        cache_str[i] = MOD(set[i], K);
    }

    sol();

    long long top = dp[(1 << N) - 1][0], bottom = 1;
    for (int i = 2; i < N + 1; i++) {
        bottom *= i;
    }
    long long gcd = GCD(top, bottom);

    std::cout << top / gcd << "/" << bottom / gcd << "\n";

    return 0;
}
