#include <iostream>
#include <algorithm>

int N, M;
int arr[100001];

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + N);

    int left = 0, right = 1;
    int minM = 2000000001;
    while (left < right) {
        int diff = arr[right] - arr[left];
        if (diff >= M) {
            minM = std::min(minM, diff);
            if (right == N - 1) {
                left++;
            } else if (left + 1 == right) {
                right++;
            } else {
                left++;
            }
        } else {
            if (right + 1 == N) {
                left++;
            } else {
                right++;
            }
        }
    }
    std::cout << minM << "\n";
    return 0;
}
