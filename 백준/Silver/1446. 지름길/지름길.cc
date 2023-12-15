#include <iostream>
#include <vector>

int N, D;
std::vector<std::vector<int>> shortcuts;
int answer;

void back_track(int current, int distance) {
    for (int i = current; i < D + 1; i++) {
        for (auto v : shortcuts) {
            if (v[0] == i && v[1] <= D) {
                back_track(v[1], distance + (i - current) + v[2]);
            }
        }
    }

    answer = std::min(answer, distance + (D - current));
}

int main() {
    std::cin >> N >> D;

    answer = D;

    for (int i = 0; i < N; i++) {
        int from = 0, to = 0, d = 0;
        std::cin >> from >> to >> d;

        if (to - from <= d) {
            continue;
        }
        std::vector<int> v;
        v.push_back(from);
        v.push_back(to);
        v.push_back(d);
        shortcuts.push_back(v);
    }

    back_track(0, 0);

    std::cout << answer << "\n";

    return 0;
}
