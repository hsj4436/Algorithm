#include <iostream>
#include <algorithm>

int T;
int N, K;
int arr[1000001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> T;

    while (T--) {
        std::cin >> N >> K;

        for (int i = 0; i < N; i++) {
            std::cin >> arr[i];
        }

        std::sort(arr, arr + N);

        int answer = 0;
        int maxDiff = 2000000001;
        int left = 0, right = N - 1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (std::abs(sum - K) < maxDiff) {
                maxDiff = std::abs(sum - K);
                answer = 1;
            } else if (std::abs(sum - K) == maxDiff) {
                answer++;
            }
            if (sum < K) {
                left++;
            } else {
                right--;
            }
        }

        std::cout << answer << "\n";
    }
    return 0;
}
