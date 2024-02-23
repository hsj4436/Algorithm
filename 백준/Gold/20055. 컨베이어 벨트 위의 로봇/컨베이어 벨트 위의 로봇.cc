#include <iostream>

int N, K;
int count[202];
int has_robot[202];
bool moved[202];

int main() {
    std::cin >> N >> K;

    int count_zero = 0;
    for (int i = 0; i < 2 * N; i++) {
        std::cin >> count[i];
        if (count[i] == 0) {
            count_zero++;
        }
    }

    int answer = 1;
    int up = 0, down = N - 1;
    int MOD = 2 * N;
    int robots = 1;
    while (true) {
        up--;
        up += MOD;
        up %= MOD;
        down--;
        down += MOD;
        down %= MOD;

        if (has_robot[(down + MOD) % MOD] > 0) {
            has_robot[(down + MOD) % MOD] = 0;
        }

        std::fill(moved, moved + 202, false);
        for (int i = 0; i < 2 * N; i++) {
            if (!moved[(up - 1 - i + MOD) % MOD] && has_robot[(up - 1 - i + MOD) % MOD] > 0 && has_robot[(up - 1 - i + 1 + MOD) % MOD] == 0 && count[(up - 1 - i + 1 + MOD) % MOD] > 0) {

                if ((up - 1 - i + 1 + MOD) % MOD != (down + MOD) % MOD) {
                    has_robot[(up - 1 - i + 1 + MOD) % MOD] = has_robot[(up - 1 - i + MOD) % MOD];
                }
                has_robot[(up - 1 - i + MOD) % MOD] = 0;
                count[(up - 1 - i + 1 + MOD) % MOD]--;

                if (count[(up - 1 - i + 1 + MOD) % MOD] == 0) {
                    count_zero++;
                }
                moved[(up - 1 - i + 1 + MOD) % MOD] = true;
            }
        }

        if (count[(up + MOD) % MOD] > 0) {
            count[(up + MOD) % MOD]--;
            if (count[(up + MOD) % MOD] == 0) {
                count_zero++;
            }
            if (count_zero >= K) {
                break;
            }
            has_robot[(up + MOD) % MOD] = robots;
        }

        if (count_zero >= K) {
            break;
        }
        answer++;
        robots++;
    }

    std::cout << answer << "\n";

    return 0;
}
