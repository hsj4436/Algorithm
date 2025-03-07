#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int N;

/**
 * lines {point, number of change}
 */
std::unordered_map<int, int> lines;

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    int s, e;
    for (int i = 0; i < N; i++) {
        std::cin >> s >> e;
        lines[s]++;
        lines[e]--;
    }
    std::vector<std::pair<int, int>> lines_copy(lines.begin(), lines.end());
    std::sort(lines_copy.begin(), lines_copy.end(), [&](std::pair<int, int> a, std::pair<int, int> b) {
        return a.first < b.first;
    });

    int max = 0;
    int current = 0;
    for (auto p : lines_copy) {
        current += p.second;
        max = std::max(max, current);
    }

    std::cout << max << "\n";

    return 0;
}
