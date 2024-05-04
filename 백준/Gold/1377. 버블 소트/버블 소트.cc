#include <iostream>
#include <algorithm>

int N;
std::pair<int, int> arr[500001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> arr[i].first;
        arr[i].second = i;
    }

    std::sort(arr + 1, arr + N + 1);

    int answer = 0;
    for (int i = 1; i < N + 1; i++) {
        answer = std::max(answer, arr[i].second - i + 1);
    }

    if (answer != 0) {
        std::cout << answer << "\n";
    }

    return 0;
}
