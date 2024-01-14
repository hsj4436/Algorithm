#include <iostream>
#include <queue>
#include <map>

int K, L;
std::map<std::string, int> list;

struct compare {
    bool operator () (std::pair<std::string, int> p1, std::pair<std::string, int> p2) {
        return p1.second > p2.second;
    }
};

int main() {
    std::cin >> K >> L;

    std::string number;
    for (int i = 0; i < L; i++) {
        std::cin >> number;
        list[number] = i;
    }

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, compare> pq;

    for (auto p : list) {
        pq.push({p.first, p.second});
    }

    int cnt = 0;
    while (cnt != K && !pq.empty()) {
        std::cout << pq.top().first << "\n";
        pq.pop();
        cnt++;
    }

    return 0;
}
