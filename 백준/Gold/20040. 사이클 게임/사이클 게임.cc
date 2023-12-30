#include <iostream>

int N, M;
int parent[500001];

int find_parent(int target) {
    if (parent[target] == target) {
        return target;
    } else {
        return parent[target] = find_parent(parent[target]);
    }
}

int main() {
    std::cin >> N >> M;

    for (int i = 1; i < N; i++) {
        parent[i] = i;
    }

    bool found = false;
    for (int i = 1; i < M + 1; i++) {
        int from, to;
        std::cin >> from >> to;
        int parent_from = find_parent(from);
        int parent_to = find_parent(to);
        if (parent_from == parent_to) {
            found = true;
            std::cout << i << "\n";
            break;
        } else {
            if (parent_from < parent_to) {
                parent[parent_to] = parent_from;
            } else {
                parent[parent_from] = parent_to;
            }
        }
    }

    if (!found) {
        std::cout << "0\n";
    }
    return 0;
}
