#include <iostream>
#include <algorithm>

#define LL long long

int N;
int heights[51];
int visible_buildings[51];

LL CCW(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3) {
    LL ccw = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;

    if (ccw > 0) {
        return 1;
    } else if (ccw == 0) {
        return 0;
    } else {
        return -1;
    }
}

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> heights[i];
    }

    for (int i = 1; i < N + 1; i++) {
        int cnt = 0;
        for (int j = 1; j < N + 1; j++) {
            if (i == j) {
                continue;
            }
            LL x1 = i, y1 = heights[i], x2 = j, y2 = heights[j];
            bool visible = true;
            for (int k = std::min(i, j) + 1; k < std::max(i, j); k++) {
                LL x3 = k, y3 = 0, x4 = k, y4 = heights[k];
                LL L1_L2 = CCW(x1, y1, x2, y2, x3, y3) * CCW(x1, y1, x2, y2, x4, y4);
                LL L2_L1 = CCW(x3, y3, x4, y4, x1, y1) * CCW(x3, y3, x4, y4, x2, y2);
                if (L1_L2 <= 0 && L2_L1 <= 0) {
                    visible = false;
                    break;
                }
            }
            if (visible) {
                cnt++;
            }
        }
        visible_buildings[i] = cnt;
    }

    std::cout << *std::max_element(visible_buildings + 1, visible_buildings + N + 1) << "\n";
    return 0;
}
