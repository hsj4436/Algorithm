#include <iostream>

int N;
int arr[100001];
int counts[100001];

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    long long answer = 0;
    int left = 0;
    for (int right = 0; right < N; right++) {
        if (counts[arr[right]] == 1) {
            while (counts[arr[right]] != 0) {
                answer += right - left;
                counts[arr[left]]--;
                left++;
            }
            counts[arr[right]]++;
        } else {
            counts[arr[right]]++;
        }
    }

    if (counts[arr[N - 1]] == 1) {
        while (counts[arr[N - 1]] != 0) {
            answer += N - 1 - left + 1;
            counts[arr[left]]--;
            left++;
        }
    }

    std::cout << answer << "\n";

    return 0;
}
