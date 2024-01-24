#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define PII std::pair<int, int>

struct compare {
    bool operator () (PII a, PII b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first > b.first;
        }
    }
};

int M, N, L;
std::vector<int> guns;
std::priority_queue<PII, std::vector<PII>, compare> animals;

int main() {
    std::cin >> M >> N >> L;
    
    guns.resize(M);
    for (int i = 0; i < M; i++) {
        std::cin >> guns[i];
    }
    
    std::sort(guns.begin(), guns.end());
    
    int a, b;
    for (int i = 0; i < N; i++) {
        std::cin >> a >> b;
        animals.push({a, b});
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        while (!animals.empty()) {
            int x = animals.top().first;
            int y = animals.top().second;
            if (std::abs(guns[i] - x) + y <= L) {
                cnt++;
                animals.pop();
            } else {
                if (x <= guns[i]) {
                    animals.pop();
                } else {
                    break;
                }
            }
        }
    }

    std::cout << cnt << "\n";

    return 0;
}