#include <iostream>
#include <algorithm>
#include <queue>

#define PII std::pair<int, int>

int N;
PII lectures[100001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    int X, S, E;
    for (int i = 0; i < N; i++) {
        std::cin >> X >> S >> E;
        lectures[i] = {S, E};
    }

    std::sort(lectures, lectures + N, [&](PII a, PII b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    });

    int answer = 1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    pq.push(lectures[0].second);
    for (int i = 1; i < N; i++) {
        if (pq.top() <= lectures[i].first) {
            while (!pq.empty()) {
                if (pq.top() > lectures[i].first) {
                    break;
                }
                pq.pop();
            }
        }
        pq.push(lectures[i].second);

        answer = std::max(answer, (int)pq.size());
    }

    std::cout << answer << "\n";

    return 0;
}
