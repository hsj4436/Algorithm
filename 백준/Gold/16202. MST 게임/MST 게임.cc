#include <iostream>
#include <vector>
#include <algorithm>

#define PII std::pair<int, int>

int N, M, K;
int X, Y;
int parents[1001];
std::vector<std::pair<int, PII>> origin;
bool erased[500001];

int find_parent(int x) {
    if (parents[x] == x) {
        return x;
    } else {
        return parents[x] = find_parent(parents[x]);
    }
}

int main() {
    std::cin >> N >> M >> K;

    for (int i = 1; i < N + 1; i++) {
        parents[i] = i;
    }

    for (int i = 1; i < M + 1; i++) {
        std::cin >> X >> Y;
        origin.push_back({i, {X, Y}});
    }

    std::sort(origin.begin(), origin.end());

    bool end = false;
    for (int turn = 0; turn < K; turn++) {
        if (end) {
            std::cout << "0 ";
            continue;
        }

        for (int i = 1; i < N + 1; i++) {
            parents[i] = i;
        }

        int turn_cost = 0;
        int cnt = 0;
        for (int i = 0; i < origin.size(); i++) {
            if (erased[i]) {
                continue;
            }
            int cost = origin[i].first;
            X = origin[i].second.first;
            Y = origin[i].second.second;

            int px = find_parent(X);
            int py = find_parent(Y);

            if (px == py) {
                continue;
            }

            if (px < py) {
                parents[py] = px;
            } else {
                parents[px] = py;
            }
            if (cnt == 0) {
                erased[i] = true;
            }
            turn_cost += cost;
            cnt++;
            if (cnt == N - 1) {
                break;
            }
        }

        if (cnt == N - 1) {
            std::cout << turn_cost << " ";
        } else {
            end = true;
            std::cout << "0 ";
        }
    }

    return 0;
}
