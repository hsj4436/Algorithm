#include <iostream>
#include <vector>
#include <algorithm>

struct brick {
    int index;
    int bottom;
    int height;
    int weight;
    brick() {};
    brick(int index, int bottom, int height, int weight) : index(index), bottom(bottom), height(height), weight(weight) {};
};

int N;
brick bricks[101];
std::pair<int, int> dp[101];    // {total_height, from}

int main() {
    std::cin >> N;

    int bottom = 0, height = 0, weight = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> bottom >> height >> weight;
        bricks[i] = brick(i + 1, bottom, height, weight);
    }

    std::sort(bricks, bricks + N, [&](brick a, brick b) {
       return a.weight > b.weight;
    });

    for (int i = 0; i < N; i++) {
        dp[i] = {bricks[i].height, -1};
    }

    int maxHeight = 0, maxHeightsIndex = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (bricks[j].bottom <= bricks[i].bottom && dp[j].first < dp[i].first + bricks[j].height) {
                dp[j] = {dp[i].first + bricks[j].height, i};
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (dp[i].first > maxHeight) {
            maxHeight = dp[i].first;
            maxHeightsIndex = i;
        }
    }

    std::vector<int> trace;
    int index = maxHeightsIndex;
    while (index != -1) {
        trace.push_back(bricks[index].index);
        index = dp[index].second;
    }

    std::cout << trace.size() << "\n";
    for (auto i : trace) {
        std::cout << i << "\n";
    }

    return 0;
}
