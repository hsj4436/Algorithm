#include <iostream>
#include <vector>

int H, W;
std::vector<int> heights;

int main() {
    std::cin >> H >> W;
    heights.resize(W);
    for (int i = 0; i < W; i++) {
        std::cin >> heights[i];
    }

    int answer = 0;
    for (int i = 1; i < W - 1; i++) {
        int left = 0, right = 0;
        for (int j = i - 1; j > -1; j--) {
            left = std::max(left, heights[j]);
        }
        for (int j = i + 1; j < W; j++) {
            right = std::max(right, heights[j]);
        }
        answer += std::max(0, std::min(left, right) - heights[i]);
    }

    std::cout << answer << "\n";

    return 0;
}
