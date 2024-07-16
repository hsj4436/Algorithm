#include <iostream>
#include <algorithm>

int N;
std::pair<int, int> papers[101];
std::pair<int, int> dp[101]; // {height, last paper}

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> papers[i].first >> papers[i].second;
        dp[i] = {1, -1};
    }

    std::sort(papers, papers + N, [&](std::pair<int, int> a, std::pair<int, int> b) {
        return a.first * a.second < b.first * b.second;
    });

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if ((papers[j].first <= papers[i].first && papers[j].second <= papers[i].second) ||
                    ((papers[j].second <= papers[i].first && papers[j].first <= papers[i].second))) {
                if (dp[j].first + 1 > dp[i].first) {
                    dp[i] = {dp[j].first + 1, j};
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        answer = std::max(answer, dp[i].first);
    }

    std::cout << answer << "\n";

    return 0;
}
