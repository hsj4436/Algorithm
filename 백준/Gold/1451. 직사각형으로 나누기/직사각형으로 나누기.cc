#include <iostream>

#define LL long long

int N, M;
LL arr[51][51];
LL answer = 0;

int main() {
    std::cin >> N >> M;

    std::string row;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> row;
        for (int j = 1; j < M + 1; j++) {
            arr[i][j] = (LL)(row[j - 1] - '0');
        }
    }
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            LL sum1 = arr[i][j] - arr[i][0] - arr[0][j] + arr[0][0];
            LL sum2 = 0;
            LL sum3 = 0;
            if (i == N) {
                for (int k = j + 1; k < M; k++) {
                    sum2 = arr[i][k] - arr[i][j] - arr[0][k] + arr[0][j];
                    sum3 = arr[N][M] - arr[i][k] - arr[0][M] + arr[0][k];
                    if (sum1 <= 0 || sum2 <= 0 || sum3 <= 0) {
                        continue;
                    }
                    if (sum1 * sum2 * sum3 > answer) {
                        answer = sum1 * sum2 * sum3;
                    }
                }
                for (int k = 1; k < N; k++) {
                    sum2 = arr[k][M] - arr[k][j] - arr[0][M] + arr[0][j];
                    sum3 = arr[N][M] - arr[N][j] - arr[k][M] + arr[k][j];
                    if (sum1 <= 0 || sum2 <= 0 || sum3 <= 0) {
                        continue;
                    }
                    if (sum1 * sum2 * sum3 > answer) {
                        answer = sum1 * sum2 * sum3;
                    }
                }
            } else if (j == M) {
                for (int k = i + 1; k < N; k++) {
                    sum2 = arr[k][j] - arr[k][0] - arr[i][M] + arr[i][0];
                    sum3 = arr[N][M] - arr[N][0] - arr[k][M] + arr[k][0];
                    if (sum1 <= 0 || sum2 <= 0 || sum3 <= 0) {
                        continue;
                    }
                    if (sum1 * sum2 * sum3 > answer) {
                        answer = sum1 * sum2 * sum3;
                    }
                }
                for (int k = 1; k < M; k++) {
                    sum2 = arr[N][k] - arr[N][0] - arr[i][k] + arr[i][0];
                    sum3 = arr[N][M] - arr[N][k] - arr[i][M] + arr[i][k];
                    if (sum1 <= 0 || sum2 <= 0 || sum3 <= 0) {
                        continue;
                    }
                    if (sum1 * sum2 * sum3 > answer) {
                        answer = sum1 * sum2 * sum3;
                    }
                }
            } else {
                sum2 = arr[N][M] - arr[N][j] - arr[0][M] + arr[0][j];
                sum3 = arr[N][j] - arr[N][0] - arr[i][j] + arr[i][0];
                if (sum1 <= 0 || sum2 <= 0 || sum3 <= 0) {
                    continue;
                }
                if (sum1 * sum2 * sum3 > answer) {
                    answer = sum1 * sum2 * sum3;
                }
                sum2 = arr[i][M] - arr[i][j] - arr[0][M] + arr[0][j];
                sum3 = arr[N][M] - arr[N][0] - arr[i][M] + arr[i][0];
                if (sum1 <= 0 || sum2 <= 0 || sum3 <= 0) {
                    continue;
                }
                if (sum1 * sum2 * sum3 > answer) {
                    answer = sum1 * sum2 * sum3;
                }
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}
