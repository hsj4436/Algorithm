#include <iostream>
#include <algorithm>

#define PII std::pair<int, int>

int N;
PII jobs[1000001]; // {time, due}

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> jobs[i].first >> jobs[i].second;
    }

    std::sort(jobs, jobs + N, [&](PII a, PII b) {
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second < b.second;
        }
    });

    int answer = 0;
    int curDay = jobs[N - 1].second;
    for (int i = N - 1; i > -1; i--) {
        if (curDay > jobs[i].second) {
            curDay = jobs[i].second;
        }
        curDay -= jobs[i].first;
    }
    answer = std::max(answer, curDay);

    std::cout << answer << "\n";

    return 0;
}
