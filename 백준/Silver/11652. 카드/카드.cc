#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

#define PII std::pair<int, int>

int N;
std::map<long long, int> m;

int main() {
    std::cin >> N;

    long long num;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        m[num]++;
    }

    std::vector<std::pair<long long, int>> vec(m.begin(), m.end());

    std::sort(vec.begin(), vec.end(), [&](std::pair<long long, int> a, std::pair<long long, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    });

    std::cout << vec[0].first << "\n";

    return 0;
}