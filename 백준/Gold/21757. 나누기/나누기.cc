#include <iostream>

#define LL long long

int N;
LL arr[100001];
LL dp[100001][4];
LL sum;

LL sol(int depth, int index) {
    if (dp[index][depth] != -1) {
        return dp[index][depth];
    }
    if (index < 1) {
        return dp[index][depth] = 0;
    }
    if (depth == 0) {
        if (arr[index] != sum) {
            return dp[index][depth] = 0;
        } else {
            return dp[index][depth] = 1;
        }
    }
    dp[index][depth] = 0;
    for (int i = index; i >= 1; i--) {
        if (arr[index] - arr[i - 1] == sum) {
            dp[index][depth] += sol(depth - 1, i - 1);
        }
    }

    return dp[index][depth];
}

int main() {
    std::cin >> N;

    std::fill_n(&dp[0][0], 100000 * 4, -1);

    for (int i = 1; i < N + 1; i++) {
        std::cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    if (arr[N] % 4 != 0) {
        std::cout << "0\n";
        return 0;
    }

    if (arr[N] == 0) {
        long long count = 0;
        for (int i = 1; i < N + 1; i++) {
            if (arr[i] == 0) {
                count++;
            }
        }
        std::cout << (count - 1) * (count - 2) * (count - 3) / 6 << "\n";
        return 0;
    }

    sum = arr[N] / 4;
    long long answer = 0;
    for (int i = N; i > 0; i--) {
        if (arr[N] - arr[i - 1] == sum) {
            answer += sol(2, i - 1);
        }
    }
    std::cout << answer << "\n";

    return 0;
}