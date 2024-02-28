#include <iostream>
#include <algorithm>
#include <vector>

int N;
std::vector<int> positive;
std::vector<int> negative;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    std::cin >> N;

    int zero_count = 0;
    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        if (num < 0) {
            negative.push_back(num);
        } else if (num > 0) {
            positive.push_back(num);
        } else {
            zero_count++;
        }
    }
    std::sort(positive.begin(), positive.end(), cmp);
    std::sort(negative.begin(), negative.end());

    long long ans = 0;
    for (int i = 0; i < positive.size(); i++) {
        if (i < positive.size() - 1) {
            if (positive[i] * positive[i + 1] > positive[i] + positive[i + 1]) {
                ans += positive[i] * positive[i + 1];
                i++;
                continue;
            }
        }
        ans += positive[i];
    }

    for (int i = 0; i < negative.size(); i++) {
        if (i < negative.size() - 1) {
            ans += negative[i] * negative[i + 1];
            i++;
        } else {
            if (zero_count > 0) {
                zero_count--;
                continue;
            }
            ans += negative[i];
        }
    }

    std::cout << ans << "\n";

    return 0;
}
