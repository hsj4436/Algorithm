#include <iostream>
#include <limits.h>

int N;
long long A[20001], C[20001], B[20001];

long long count_of(long long x) {
    long long count = 0;
    for (int i = 0; i < N; i++) {
        if (x < A[i]) {
            continue;
        }
        count += ((std::min(C[i], x) - A[i]) / B[i]) + 1;
    }

    return count;
}

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> C[i] >> B[i];
    }

    long long left = 1, right = INT_MAX;
    long long result = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (count_of(mid) % 2 == 1) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (result != 0) {
        std::cout << result << " ";
    } else {
        std::cout << "NOTHING\n";
        return 0;
    }

    std::cout << count_of(result) - count_of(result - 1) << "\n";

    return 0;
}