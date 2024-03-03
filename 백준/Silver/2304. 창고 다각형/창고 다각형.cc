#include <iostream>
#include <algorithm>

int N;
std::pair<int, int> bars[1001];

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> bars[i].first >> bars[i].second;
    }
    std::sort(bars, bars + N);
    int max_H = 0;
    int max_index = 0;
    for (int i = 0; i < N; i++) {
        if (bars[i].second > max_H) {
            max_H = bars[i].second;
            max_index = i;
        }
    }

    int answer = max_H;
    int L = 0, H = 0;
    for (int i = 0; i < max_index + 1; i++) {
        if (L == 0 && H == 0) {
            L = bars[i].first;
            H = bars[i].second;
            continue;
        }
        if (bars[i].second >= H) {
            answer += (bars[i].first - L) * H;
            L = bars[i].first;
            H = bars[i].second;
        }
    }
    L = 0, H = 0;
    for (int i = N - 1; i > max_index - 1; i--) {
        if (L == 0 && H == 0) {
            L = bars[i].first + 1;
            H = bars[i].second;
        }
        if (bars[i].second >= H) {
            answer += (L - bars[i].first - 1) * H;
            L = bars[i].first + 1;
            H = bars[i].second;
        }
    }

    std::cout << answer << "\n";

    return 0;
}
