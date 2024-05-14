#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int N, M;
std::priority_queue<int> pq[101];
int scores[101];

int main() {
    std::cin >> N >> M;

    for (int i = 1; i < N + 1; i++) {
        int m;
        for (int j = 0; j < M; j++) {
            std::cin >> m;
            pq[i].push(m);
        }
    }

    for (int i = 0; i < M; i++) {
        int maxNumber = 0;
        std::vector<int> winners;
        for (int j = 1; j < N + 1; j++) {
            int number = pq[j].top();
            pq[j].pop();
            if (number > maxNumber) {
                maxNumber = number;
                winners.clear();
                winners.push_back(j);
            } else if (number == maxNumber) {
                winners.push_back(j);
            }
        }
        for (int winner : winners) {
            scores[winner]++;
        }
    }

    int maxScore = *std::max_element(scores + 1, scores + N + 1);
    for (int i = 1; i < N + 1; i++) {
        if (maxScore == scores[i]) {
            std::cout << i << " ";
        }
    }

    return 0;
}
