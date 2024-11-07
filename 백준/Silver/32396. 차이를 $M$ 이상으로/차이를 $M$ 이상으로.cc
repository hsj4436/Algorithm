#include <iostream>

#define LL long long
#define INF -2000000000001

int N;
LL M;
LL arr[1000003];

int main() {
    std::cin >> N >> M;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> arr[i];
    }

    int count = 0;
    for (int i = 2; i < N + 1; i++) {
        if (std::abs(arr[i] - arr[i - 1]) < M) {
            arr[i] = std::min(arr[i - 1], arr[i + 1]) + INF;
            count++;
        }
    }

    std::cout << count << "\n";

    return 0;
}
