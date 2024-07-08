#include <iostream>
#include <vector>
#include <queue>

struct edge {
    int from;
    int to;
    long long cost;
    edge(){}
    edge(int from, int to, long long cost) : from(from), to(to), cost(cost) {}
};

struct cmp {
    bool operator() (edge a, edge b) {
        return a.cost > b.cost;
    }
};

int N, M;
int parent[100001];

int findParent(int target) {
    if (parent[target] == target) {
        return target;
    } else {
        return parent[target] = findParent(parent[target]);
    }
}

int main() {
    std::cin >> N >> M;

    for (int i = 1; i < N + 1; i++) {
        parent[i] = i;
    }

    int a, b;
    long long c;
    std::priority_queue<edge, std::vector<edge>, cmp> pq;
    long long totalCost = 0;
    for (int i = 0; i < M; i++) {
        std::cin >> a >> b >> c;
        pq.push(edge(a, b, c));
        totalCost += c;
    }

    int count = 0;
    long long minimumCost = 0;
    while (!pq.empty()) {
        edge cur = pq.top();
        pq.pop();

        int pFrom = findParent(cur.from);
        int pTo = findParent(cur.to);

        if (pFrom == pTo) {
            continue;
        }

        if (pFrom < pTo) {
            parent[pTo] = pFrom;
        } else {
            parent[pFrom] = pTo;
        }
        minimumCost += cur.cost;
        count++;
        if (count == N - 1) {
            std::cout << totalCost - minimumCost << "\n";
            return 0;
        }
    }

    std::cout << "-1\n";
    
    return 0;
}
