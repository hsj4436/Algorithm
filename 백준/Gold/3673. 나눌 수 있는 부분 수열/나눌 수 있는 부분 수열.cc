#include <iostream>

#define LL long long

int C;
LL D, N;
LL arr[50001];
LL remain[1000001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> C;

    while (C--) {
        std::cin >> D >> N;

        std::fill_n(remain, 1000001, 0);
        for (int i = 1; i < N + 1; i++) {
            std::cin >> arr[i];
            arr[i] += arr[i - 1];
            remain[arr[i] % D]++;
        }

        LL answer = remain[0];
        for (int i = 0; i < D; i++) {
            answer += remain[i] * (remain[i] - 1) / 2;
        }

        std::cout << answer << "\n";
    }
    return 0;
}
