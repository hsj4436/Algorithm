#include <iostream>

int N;
int temporalArr[500001];
int arr[500001];
long long answer = 0;

void mergeSort(int start, int end) {
    if (start == end) {
        return;
    }

    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);

    for (int i = start; i < end + 1; i++) {
        temporalArr[i] = arr[i];
    }

    int index = start;
    int left = start, right = mid + 1;
    while (left <= mid && right <= end) {
        if (temporalArr[left] <= temporalArr[right]) {
            arr[index] = temporalArr[left];
            index++;
            left++;
        } else {
            arr[index] = temporalArr[right];
            answer += right - index;
            index++;
            right++;
        }
    }

    while (left <= mid) {
        arr[index] = temporalArr[left];
        index++;
        left++;
    }

    while (right <= end) {
        arr[index] = temporalArr[right];
        index++;
        right++;
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    mergeSort(0, N - 1);

    std::cout << answer << "\n";

    return 0;
}
