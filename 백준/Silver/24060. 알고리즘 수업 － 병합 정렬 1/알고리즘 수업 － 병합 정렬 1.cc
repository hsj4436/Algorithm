#include <iostream>

int N, K;
int arr[500001];
int tmp[500001];
int cnt;
int answer = 0;
void merge(int L, int mid, int R) {
    int i = L, j = mid + 1, t = 1;
    while (i <= mid && j <= R) {
        if (arr[i] <= arr[j]) {
            tmp[t++] = arr[i++];
        } else {
            tmp[t++] = arr[j++];
        }
    }
    while (i <= mid) {
        tmp[t++] = arr[i++];
    }
    while (j <= R) {
        tmp[t++] = arr[j++];
    }
    i = L, t = 1;
    while (i <= R) {
        cnt++;
        if (cnt == K) {
            answer = tmp[t];
        }
        arr[i++] = tmp[t++];
    }
}

void merge_sort(int L, int R) {
    if (L < R) {
        int mid = (L + R) / 2;
        merge_sort(L, mid);
        merge_sort(mid + 1, R);
        merge(L, mid, R);
    }
}

int main() {
    std::cin >> N >> K;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> arr[i];
    }

    merge_sort(1, N);

    if (answer == 0) {
        std::cout << "-1\n";
    } else {
        std::cout << answer << "\n";
    }
    return 0;
}
