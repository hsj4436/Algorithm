#include <iostream>
#include <vector>
#include <algorithm>

int T;
int N, M;
std::vector<int> A;
std::vector<int> B;

int main() {
    std::cin >> T;

    while (T--) {
        std::cin >> N >> M;

        int n;
        A.clear();
        for (int i = 0; i < N; i++) {
            std::cin >> n;
            A.push_back(n);
        }
        B.clear();
        for (int i = 0; i < M; i++) {
            std::cin >> n;
            B.push_back(n);
        }

        std::sort(A.begin(), A.end());
        std::sort(B.begin(), B.end());

        int answer = 0;
        for (int i = 0; i < M; i++) {
            answer += A.end() - std::upper_bound(A.begin(), A.end(), B[i]);
        }
        std::cout << answer << "\n";
    }
    return 0;
}
