#include <iostream>
#include <algorithm>
#include <vector>

#define PII std::pair<int, int>

int N;
PII homeworks[1001];    // deadline, score
int parent[1001];

int findParent(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = findParent(parent[x]);
    }
}

int main() {
    std::cin >> N;

    for (int i = 0; i < 1001; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < N; i++) {
        std::cin >> homeworks[i].first >> homeworks[i].second;
    }

    std::sort(homeworks, homeworks + N, [&](PII a, PII b) {
       if (a.second == b.second) {
           return a.first > b.first;
       } else {
           return a.second > b.second;
       }
    });

    int answer = 0;
    for (int i = 0; i < N; i++) {
        int pDay = findParent(homeworks[i].first);
        if (pDay > 0) {
            parent[pDay] = parent[pDay] - 1;
            answer += homeworks[i].second;
        }
    }

    std::cout << answer << "\n";

    return 0;
}
