#include <iostream>

int N, M;
int arr[5001];

int main() {
    std::cin >> N >> M;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> arr[i];
    }

    int answer = 0;
    int left = 0, right = 20001;
    while (left <= right) {
        int mid = (left + right) / 2;
        int minOfSector = arr[1], maxOfSector = arr[1];
        int score = 0;
        int numberOfSector = 1;
        for (int i = 2; i < N + 1; i++) {
            minOfSector = std::min(minOfSector, arr[i]);
            maxOfSector = std::max(maxOfSector, arr[i]);
            score = maxOfSector - minOfSector;
            if (score > mid) {
                minOfSector = arr[i];
                maxOfSector = arr[i];
                score = 0;
                numberOfSector++;
                if (numberOfSector > M) {
                    break;
                }
            }
        }
        if (numberOfSector > M) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    std::cout << left << "\n";

    return 0;
}
