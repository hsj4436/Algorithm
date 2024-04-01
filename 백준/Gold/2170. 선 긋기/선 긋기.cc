#include <iostream>
#include <algorithm>

#define LL long long
#define PLL std::pair<LL, LL>

int N;
PLL lines[1000001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> lines[i].first >> lines[i].second;
    }
    std::sort(lines, lines + N, [&](PLL a, PLL b) {
       if (a.first == b.first) {
           return a.second < b.second;
       } else {
           return a.first < b.first;
       }
    });

    LL answer = 0;
    LL left = lines[0].first, right = lines[0].second;
    for (int i = 1; i < N; i++) {
        if (i == N - 1) {
            if (lines[i].first <= right) {
                right = std::max(right, lines[i].second);
                left = std::min(left, lines[i].first);
                answer += right - left;
            } else {
                answer += right - left;
                left = lines[i].first;
                right = lines[i].second;
                answer += right - left;
            }
        } else {
            if (lines[i].first <= right) {
                right = std::max(right, lines[i].second);
                left = std::min(left, lines[i].first);
            } else {
                answer += right - left;
                left = lines[i].first;
                right = lines[i].second;
            }
        }
    }
    if (N == 1) {
        answer = right - left;
    }

    std::cout << answer << "\n";
    return 0;
}
