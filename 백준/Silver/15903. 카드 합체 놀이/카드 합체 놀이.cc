#include <iostream>
#include <queue>

#define LL long long

int N, M;

int main() {
    std::cin >> N >> M;

    std::priority_queue<LL, std::vector<LL>, std::greater<LL>> pq;
    LL card;
    for (int i = 0; i < N; i++) {
        std::cin >> card;
        pq.push(card);
    }

    for (int i = 0; i < M; i++) {
        LL n1 = pq.top();
        pq.pop();
        LL n2 = pq.top();
        pq.pop();
        pq.push(n1 + n2);
        pq.push(n1 + n2);
    }

    LL answer = 0;
    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }

    std::cout << answer << "\n";

    return 0;
}
