#include <iostream>
#include <queue>

int N;
int initialHeight[100001];
int growSize[100001];

struct cmp {
    bool operator()(std::pair<int, int> lhs, std::pair<int, int> rhs) {
        if (lhs.second == rhs.second) {
            return lhs.first > rhs.first;
        } else {
            return lhs.second < rhs.second;
        }
    }
};

int main() {
    std::cin >> N;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> pq;
    for (int i = 0; i < N; i++) {
        std::cin >> initialHeight[i];
    }

    for (int i = 0; i < N; i++) {
        std::cin >> growSize[i];
    }

    for (int i = 0; i < N; i++) {
        pq.push({initialHeight[i], growSize[i]});
    }

    long long answer = 0;
    int i = 0;
    while (i != N) {
        std::pair<int, int> left = pq.top();
        pq.pop();

        answer += left.first + (left.second * (N - i - 1));
        i++;
    }

    std::cout << answer << "\n";

    return 0;
}
