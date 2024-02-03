#include <iostream>
#include <vector>
#include <algorithm>

#define PII std::pair<int, int>

int N;
std::vector<int> sw;
std::vector<int> bulb;
int bulb_index[10001] = {0, };
std::vector<int> LIS;
std::vector<PII> switch_order;

int main() {
    std::cin >> N;
    sw.resize(N + 2);
    bulb.resize(N + 2);

    for (int i = 0; i < N; i++) {
        std::cin >> sw[i];
    }

    for (int i = 0; i < N; i++) {
        std::cin >> bulb[i];
        bulb_index[bulb[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        if (LIS.empty() || bulb_index[LIS.back()] < bulb_index[sw[i]]) {
            LIS.push_back(sw[i]);
            switch_order.push_back({LIS.size() - 1, sw[i]});
        } else {
            int left = 0, right = LIS.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (bulb_index[LIS[mid]] < bulb_index[sw[i]]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            LIS[right] = sw[i];
            switch_order.push_back({right, sw[i]});
        }
    }

    std::cout << LIS.size() << "\n";

    std::vector<int> answer;
    int idx = LIS.size() - 1;
    for (int i = N - 1; i > -1; i--) {
        if (switch_order[i].first == idx) {
            answer.push_back(switch_order[i].second);
            idx--;
        }
        if (idx == -1) {
            break;
        }
    }

    std::sort(answer.begin(), answer.end());

    for (int s : answer) {
        std::cout << s << " ";
    }

    return 0;
}