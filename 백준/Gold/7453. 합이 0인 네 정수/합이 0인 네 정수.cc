#include <iostream>
#include <vector>
#include <algorithm>

int N;
int A[4001];
int B[4001];
int C[4001];
int D[4001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    std::sort(A, A + N);
    std::sort(B, B + N);
    std::sort(C, C + N);
    std::sort(D, D + N);

    std::vector<int> cdSum;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cdSum.push_back(C[i] + D[j]);
        }
    }
    std::sort(cdSum.begin(), cdSum.end());

    long long answer = 0;
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            int sum = A[a] + B[b];
            auto lb = std::lower_bound(cdSum.begin(), cdSum.end(), -sum);
            auto ub = std::upper_bound(cdSum.begin(), cdSum.end(), -sum);
            answer += ub - lb;
        }
    }

    std::cout << answer << "\n";

    return 0;
}
