#include <iostream>
#include <vector>
#include <algorithm>

int N, M, K;
std::vector<int> cards;
int parent[4000001];

int find_parent(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = find_parent(parent[x]);
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    std::cin >> N >> M >> K;

    cards.resize(M);

    for (int i = 0; i < M; i++) {
        std::cin >> cards[i];
    }

    std::sort(cards.begin(), cards.end());

    for (int i = 1; i < N + 1; i++) {
        parent[i] = i;
    }

    int n;
    for (int i = 0; i < K; i++) {
        std::cin >> n;
        auto it = std::upper_bound(cards.begin(), cards.end(), n);
        int p = find_parent(*it);
        std::cout << p << "\n";
        parent[p] = p + 1;
    }

    return 0;
}