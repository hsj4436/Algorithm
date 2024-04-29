#include <iostream>
#include <vector>
#include <algorithm>

struct ball {
    int index;
    int color;
    int size;
    ball() {}
    ball(int index, int color, int size) : index(index), color(color), size(size) {}
};

int N;
ball balls[200001];
int answer[200001];
int sum = 0;
int sumPerColor[200001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    int color, size;
    int maxColor = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> color >> size;
        balls[i + 1] = ball(i + 1, color, size);
        maxColor = std::max(color, maxColor);
    }

    std::sort(balls + 1, balls + N + 1, [&](ball a, ball b) {
        if (a.size == b.size) {
            return a.color > b.color;
        } else {
            return a.size < b.size;
        }
    });

    balls[0] = ball(0, 0, 0);
    std::vector<std::pair<int, int>> sameSize;
    for (int i = 1; i < N + 1; i++) {
        if (balls[i].size != balls[i - 1].size) {
            for (auto p : sameSize) {
                sum += p.second;
                sumPerColor[p.first] += p.second;
            }
            sameSize.clear();
        }
        sameSize.push_back({balls[i].color, balls[i].size});
        answer[balls[i].index] = sum - sumPerColor[balls[i].color];
    }

    for (int i = 1; i < N + 1; i++) {
        std::cout << answer[i] << "\n";
    }

    return 0;
}
