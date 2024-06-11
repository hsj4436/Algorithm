#include <iostream>

int N;
int parent[300001];

int findParent(int target) {
    if (parent[target] == target) {
        return target;
    } else {
        return parent[target] = findParent(parent[target]);
    }
}

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        parent[i] = i;
    }

    int x, y;
    for (int i = 0; i < N - 2; i++) {
        std::cin >> x >> y;

        int px = findParent(x);
        int py = findParent(y);

        if (px == py) {
            continue;
        }
        if (px < py) {
            parent[py] = px;
        } else {
            parent[px] = py;
        }
    }

    for (int i = 1; i < N + 1; i++) {
        parent[i] = findParent(i);
    }

    int lastIsland = -1;
    for (int i = 1; i < N + 1; i++) {
        if (lastIsland == -1) {
            lastIsland = i;
            std::cout << i << " ";
        } else if (parent[i] != parent[lastIsland]) {
            std::cout << i << "\n";
            break;
        }
    }
    return 0;
}
