#include <iostream>
#include <vector>
#include <algorithm>

int M, N, L;
std::vector<int> guns;

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> M >> N >> L;
    
    guns.resize(M);
    for (int i = 0; i < M; i++) {
        std::cin >> guns[i];
    }
    
    std::sort(guns.begin(), guns.end());

    int cnt = 0;
    int x, y;
    for (int i = 0; i < N; i++) {
        std::cin >> x >> y;
        if (y > L) {
            continue;
        }
        int left = 0, right = M - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (std::abs(guns[mid] - x) + y <= L) {
                cnt++;
                break;
            } else {
                if (guns[mid] <= x) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
    }

    std::cout << cnt << "\n";

    return 0;
}