#include <iostream>

int V, E;
int counts[3001];
int parents[3001];

int findParent(int target) {
    if (parents[target] == target) {
        return target;
    } else {
        return parents[target] = findParent(parents[target]);
    }
}

int main() {
    std::cin >> V >> E;

    for (int i = 1; i < V + 1; i++) {
        parents[i] = i;
    }

    int va, vb;
    for (int i = 0; i < E; i++) {
        std::cin >> va >> vb;
        counts[va]++;
        counts[vb]++;
        int pVa = findParent(va);
        int pVb = findParent(vb);
        if (pVa == pVb) {
            continue;
        }
        if (pVa < pVb) {
            parents[vb] = va;
        } else {
            parents[va] = vb;
        }
    }
    
    for (int i = 1; i < V + 1; i++) {
        parents[i] = findParent(i);
    }

    int odds = 0;
    for (int i = 1; i < V + 1; i++) {
        if (i > 1 && parents[i] != parents[i - 1]) {
            std::cout << "NO\n";
            return 0;
        }
        if (counts[i] % 2 != 0) {
            odds++;
        }
        if (counts[i] == 0) {
            std::cout << "NO\n";
            return 0;
        }
    }

    if (odds == 0 || odds == 2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
