#include <iostream>
#include <algorithm>

int arr[10001];

int main() {
    int N;
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> arr[i];
    }

    int idx = N;
    while (idx > 1 && arr[idx - 1] > arr[idx]) {
        idx--;
    }
    if (idx == 1) {
        std::cout << "-1\n";
        return 0;
    }

    int right_idx = N;
    while (right_idx > idx && arr[idx - 1] > arr[right_idx]) {
        right_idx--;
    }

    std::swap(arr[idx - 1], arr[right_idx]);

    std::sort(arr + idx, arr + N + 1);

    for (int i = 1; i < N + 1; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
