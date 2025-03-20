#include <iostream>

int N;
int A, B;
int P[101];
int Q[101];
int R[101];
int S[101];
int dp[101][2][101][101]; // 일, 휴게실 사용여부, 요양횟수, 정독실과 소학습실 횟수

int sol(int day, bool prev, int rest, int study) {
    if (day == N + 1) {
        if (study < B) {
            return -1000001;
        }
        return 0;
    }

    if (dp[day][prev][rest][study] != -1) {
        return dp[day][prev][rest][study];
    }

    int ret = -1000001;
    ret = std::max(ret, sol(day + 1, false, rest, study + 1) + P[day]);
    ret = std::max(ret, sol(day + 1, false, rest, study + 1) + Q[day]);
    if (!prev) {
        ret = std::max(ret, sol(day + 1, true, rest, study) + R[day]);
    }
    if (rest < A) {
        ret = std::max(ret, sol(day + 1, false, rest + 1, study) + S[day]);
    }

    return dp[day][prev][rest][study] = ret;
}

int main() {
    std::cin >> N;
    std::cin >> A >> B;
    A = std::min(A, N - B);

    for (int i = 1; i < N + 1; i++) {
        std::cin >> P[i] >> Q[i] >> R[i] >> S[i];
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < A + 1; k++) {
                for (int l = 0; l < N + 1; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }

    std::cout << sol(1, 0, 0, 0) << "\n";

    return 0;
}
