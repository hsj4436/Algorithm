#include <iostream>
#include <map>

int N, M, K;
std::string desk[51];
std::map<std::string, int> samePatterns;

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> desk[i];
    }

    std::cin >> K;

    for (int i = 0; i < N; i++) {
        int zeros = 0;
        for (int j = 0; j < M; j++) {
            if (desk[i][j] == '0') {
                zeros++;
            }
        }
        if (zeros > K || zeros % 2 != K % 2) {
            continue;
        }
        samePatterns[desk[i]]++;
    }

    int answer = 0;
    for (auto p : samePatterns) {
        answer = std::max(answer, p.second);
    }

    std::cout << answer << "\n";

    return 0;
}
