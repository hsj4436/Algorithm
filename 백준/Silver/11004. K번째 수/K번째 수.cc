#include <iostream>
#include <algorithm>

int N, K;
int arr[5000001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    std::cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    
    std::sort(arr, arr + N);
    
    std::cout << arr[K - 1] << "\n";
}