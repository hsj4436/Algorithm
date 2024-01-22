#include <iostream>
#include <vector>
#include <algorithm>

#define PII std::pair<int, int>

int N, M, L, K;
std::vector<int> xs;
std::vector<PII> vec;

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> M >> L >> K;

    int x, y;
    for (int i = 0; i < K; i++) {
        std::cin >> x >> y;
        xs.push_back(x);
        vec.push_back({x, y});
    }

    std::sort(vec.begin(), vec.end(), [&](PII a, PII b) {
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second < b.second;
        }
    });

    std::sort(xs.begin(), xs.end());

    int answer = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            int LTX = xs[i];
            int LTY = vec[j].second;
            int cnt = 0;
            for (int k = j; k < K; k++) {
                if (vec[k].second > LTY + L) {
                    break;
                }
                if ((LTX <= vec[k].first && vec[k].first <= LTX + L) && (LTY <= vec[k].second && vec[k].second <= LTY + L)) {
                    cnt++;
                }
            }
            answer = std::max(answer, cnt);
        }
    }

    std::cout << K - answer << "\n";

    return 0;
}