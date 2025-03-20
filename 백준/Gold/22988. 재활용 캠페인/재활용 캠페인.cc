#include <iostream>
#include <algorithm>

#define LL long long

LL N, X;
LL caps[100001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> X;

    for (int i = 0; i < N; i++) {
        std::cin >> caps[i];
    }

    std::sort(caps, caps + N);

    int answer = 0;
    int left = 0, right = N - 1;
    for (; right > -1; right--) {
        if (caps[right] == X) {
            answer++;
        } else {
            break;
        }
    }

    int notUsed = 0;
    while (left <= right) {
        if (left < right && caps[right] + caps[left] >= (X + 1) / 2) {
            answer++;
            right--;
            left++;
        } else {
            left++;
            notUsed++;
        }
    }

    std::cout << answer + (notUsed / 3) << "\n";

    return 0;
}

