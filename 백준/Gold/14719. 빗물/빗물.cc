#include <iostream>
#include <vector>
#include <algorithm>

int H, W;
std::vector<int> heights;

int main() {
    std::cin >> H >> W;
    heights.resize(W);
    for (int i = 0; i < W; i++) {
        std::cin >> heights[i];
    }

    int answer = 0;
    int left = 0;
    for (int i = 0; i < W;) {
        int it = -1;
        for (int  j = left + 1; j < W; j++) {
            if (heights[j] >= heights[left]) {
                it = j;
                break;
            }
        }
        if (it == -1) {
            int max_height = 0, max_index = 0;
            for (int j = left + 1; j < W; j++) {
                if (heights[j] > max_height) {
                    max_height = heights[j];
                    max_index = j;
                }
            }
            if (max_height == 0) {
                break;
            }
            it = max_index;
            for (int j = left + 1; j < it; j++) {
                answer += heights[it] - heights[j];
            }
            left = it;
            i = left;
        } else {
            for (int j = left; j < it; j++) {
                answer += heights[left] - heights[j];
            }
            i = it;
            left = it;
        }
    }

    std::cout << answer << "\n";

    return 0;
}
