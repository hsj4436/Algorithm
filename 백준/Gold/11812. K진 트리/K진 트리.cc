#include <iostream>
#include <math.h>

long long int N, K, Q;

long long int get_parent(long long int node) {
    return (node - 2) / K + 1;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> K >> Q;
    for (int i = 0; i < Q; i++) {
        long long int x, y;
        std::cin >> x >> y;
        
        if (K == 1) {
            std::cout << std::abs(x - y) << "\n";
            continue;
        }

        long long int distance = 0;

        while (x != y) {
            if (x < y) {
                y = get_parent(y);
            } else {
                x = get_parent(x);
            }
            distance++;
        }

        std::cout << distance << "\n";
    }
    

    return 0;
}
