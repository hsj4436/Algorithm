#include <iostream>
#include <vector>
#include <algorithm>

long long N;
std::vector<long long> v;

int main() {
    std::cin >> N;
    long long num;
    std::cin >> num;
    v.push_back(num);

    for (int i = 1; i < N; i++) {
        std::cin >> num;
        v.push_back(num);
    }

    std::sort(v.begin(), v.end());

    if (N == 1) {
        std::cout << num * num << "\n";
    } else {
        std::cout << v[0] * v[N - 1] << "\n";
    }
    return 0;
}
