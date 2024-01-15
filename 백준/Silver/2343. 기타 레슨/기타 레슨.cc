#include <iostream>

int N, M;
int lectures[100001];

int main() {
    std::cin >> N >> M;

    int longest = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> lectures[i];
        longest = std::max(longest, lectures[i]);
        sum += lectures[i];
    }

    int left = longest, right = sum;
    int answer = 987654321;
    while (left <= right) {
        int mid = (left + right) / 2;
        int disks = 1, length = 0;
        int largest_disk = 0;
        for (int i = 0; i < N; i++) {
            if (length + lectures[i] <= mid) {
                length += lectures[i];
            } else {
                disks++;
                largest_disk = std::max(largest_disk, length);
                length = lectures[i];
            }
        }
        largest_disk = std::max(largest_disk, length);
        if (disks <= M) {
            right = mid - 1;
            answer = std::min(answer, largest_disk);
        } else {
            left = mid + 1;
        }
    }

    std::cout << answer << "\n";

    return 0;
}
