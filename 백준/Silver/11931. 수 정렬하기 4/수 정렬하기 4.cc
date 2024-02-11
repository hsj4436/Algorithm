#include <iostream>
#include <algorithm>

int N;
int arr[1000001];

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + N, std::greater<int>());

    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << "\n";
    }

    return 0;
}
