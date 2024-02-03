#include <iostream>

int N, M;
long long times[10001];

long long solve(long long t) {
    long long ret = 0;
    for (int i = 1; i < M + 1; i++) {
        ret += t / times[i] + 1;
    }

    return ret;
}

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> M;

    for (int i = 1; i < M + 1; i++) {
        std::cin >> times[i];
    }

    long long left = 0, right = 2000000000 / 30 + 1;
    long long T = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (solve(mid) >= N) {
            T = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    long long ans = 0;
    long long already_ride = 0;
    if (T == 0) {
        already_ride = 0;
    } else {
        already_ride = solve(T - 1);
    }

    for (int i = 1; i < M + 1; i++) {
        if (T % times[i] == 0) {
            ans = i;
            already_ride++;
        }
        if (already_ride == N) {
            break;
        }
    }

    std::cout << ans << "\n";

    return 0;
}