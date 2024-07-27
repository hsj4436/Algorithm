#include <iostream>
#include <vector>
#include <algorithm>

#define LL long long
#define PLL std::pair<LL, LL>

int N;
LL D;
std::vector<PLL> presents;

int main() {
    std::cin >> N >> D;

    LL P, V;
    for (int i = 0; i < N; i++) {
        std::cin >> P >> V;
        presents.push_back({P, V});
    }

    std::sort(presents.begin(), presents.end(), [&](PLL a, PLL b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    });

    LL answer = 0;
    int left = 0, right = 0;
    LL sum = 0;
    while (left <= right && right < presents.size()) {
        if (presents[right].first - presents[left].first < D) {
            sum += presents[right].second;
            right++;
        } else {
            sum -= presents[left].second;
            left++;
        }
        answer = std::max(answer, sum);
    }

    std::cout << answer << "\n";

    return 0;
}
