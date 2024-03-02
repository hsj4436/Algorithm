#include <iostream>
#include <queue>

struct pair {
    int num;
    int index;
    pair(int num, int index) {
        this->num = num;
        this->index = index;
    }
};

struct cmp {
    bool operator()(const pair& p1, const pair& p2) {
        return p1.num > p2.num;
    }
};

int N, L;
std::priority_queue<pair, std::vector<pair>, cmp> pq;

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> L;

    int number = 0;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> number;
        while (!pq.empty()) {
            if (pq.top().index >= i - L + 1) {
                break;
            }
            pq.pop();
        }
        pq.push({number, i});
        std::cout << pq.top().num << " ";
    }

    return 0;
}