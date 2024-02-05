#include <iostream>
#include <algorithm>

int N;
int A[10001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A, A + N);

    long long answer = 0;
    for (int i = 0; i < N - 2; i++) {
        if (A[i] > 0) {
            break;
        }
        for (int j = i + 1; j < N - 1; j++) {
            int sum = A[i] + A[j];
            if (sum > 0) {
                break;
            }
            int it1 = std::upper_bound(A + j + 1, A + N, -sum - 1) - A;
            int it2 = std::upper_bound(A + j + 1, A + N, -sum) - A;
            if (A[it1] == -sum) {
                answer += it2 - it1;
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}