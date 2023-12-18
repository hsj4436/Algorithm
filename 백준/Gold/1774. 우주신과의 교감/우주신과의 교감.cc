#include <iostream>
#include <math.h>
#include <queue>

int N, M;
std::pair<int, int> gods[1001];
int parents[1001];

struct edge {
    int from;
    int to;
    double distance;
//    int dx;
//    int dy;
    edge(int from, int to) {
        this->from = from;
        this->to = to;
        this->distance = std::sqrt(std::pow(gods[from].first - gods[to].first, 2) + std::pow(gods[from].second - gods[to].second, 2));
//        this->dx = std::abs(gods[from].first - gods[to].first);
//        this->dy = std::abs(gods[from].second - gods[to].second);
    }
};

struct cmp {
    bool operator () (edge e1, edge e2) {
//        return e1.dx + e1.dy > e2.dx + e2.dy;
        return e1.distance > e2.distance;
    }
};

int find_parent(int target) {
    if (parents[target] == target) {
        return target;
    } else {
        return parents[target] = find_parent(parents[target]);
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> M;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> gods[i].first >> gods[i].second;
        parents[i] = i;
    }

    int connected = 0;
    for (int i = 0; i < M; i++) {
        int from = 0, to = 0;
        std::cin >> from >> to;
        int parent_from = find_parent(from);
        int parent_to = find_parent(to);
        if (parent_from == parent_to) {
            continue;
        }
        if (parent_from > parent_to) {
            parents[parent_to] = parent_from;
        } else {
            parents[parent_from] = parent_to;
        }
        connected++;
    }

    std::priority_queue<edge, std::vector<edge>, cmp> pq;

    for (int i = 1; i < N + 1; i++) {
        for (int j = i + 1; j < N + 1; j++) {
            if (parents[i] == parents[j]) {
                continue;
            }
            pq.push(edge(i, j));
        }
    }

    int cnt = 0;
    double to_make = 0.0;
    while (cnt != N - connected - 1) {
        edge e = pq.top();
        pq.pop();

        int parent_from = find_parent(e.from);
        int parent_to = find_parent(e.to);

        if (parent_from == parent_to) {
            continue;
        }

        if (parent_from > parent_to) {
            parents[parent_to] = parent_from;
        } else {
            parents[parent_from] = parent_to;
        }

//        to_make += std::sqrt(std::pow(e.dx, 2) + std::pow(e.dy, 2));
        to_make += e.distance;
        cnt++;
    }

    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << to_make << "\n";

    return 0;
}
