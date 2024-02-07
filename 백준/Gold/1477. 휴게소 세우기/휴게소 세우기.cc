#include <iostream>
#include <vector>
#include <algorithm>

int N, M, L;
std::vector<int> v;

int main() {
    std::cin >> N >> M >> L;

    v.push_back(0);
    int n;
    for (int i = 0; i < N; i++) {
        std::cin >> n;
        v.push_back(n);
    }
    v.push_back(L);

    std::sort(v.begin(), v.end());

    int left = 1, right = L - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int count = 0;
        for (int i = 1; i < v.size(); i++) {
            int distance = v[i] - v[i - 1];
            count += distance / mid;
            if (distance % mid == 0) {
                count--;
            }
        }

        if (count <= M) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    std::cout << left << "\n";

    return 0;
}