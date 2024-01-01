#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        std::cin >> scores[i];
    }
    std::sort(scores.begin(), scores.end());
    std::cout << scores[N - K] << "\n";
    
    return 0;
}