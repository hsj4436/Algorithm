#include <iostream>

int n, m;
int parents[201];
int plan[1001];

int find_set(int target) {
    if (target == parents[target]) {
        return target;
    } else {
        return parents[target] = find_set(parents[target]);
    }
}

int main() {
    std::cin >> n;
    std::cin >> m;
    
    for (int i = 1; i < n + 1; i++) {
        parents[i] = i;
    }
    
    bool input;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            std::cin >> input;
            if (input) {
                int root_i = find_set(i);
                int root_j = find_set(j);
                if (root_i < root_j) {
                    parents[root_i] = root_j;
                } else {
                    parents[root_j] = root_i;
                }
            }
        }
    }

    bool possible = true;
    std::cin >> plan[0];
    for (int i = 1; i < m; i++) {
        std::cin >> plan[i];
        if (find_set(plan[i - 1]) != find_set(plan[i])) {
            possible = false;
        }
    }

    if (possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
