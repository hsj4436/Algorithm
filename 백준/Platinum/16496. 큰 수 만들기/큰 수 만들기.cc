#include <iostream>
#include <algorithm>

int N;
int arr[1001];

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + N, [&](int a, int b) {
        std::string strA = std::to_string(a);
        std::string strB = std::to_string(b);
        return strA + strB > strB + strA;
    });

    std::string answer;
    for (int i = 0; i < N; i++) {
        answer += std::to_string(arr[i]);
    }

    if (answer[0] == '0') {
        answer = "0";
    }

    std::cout << answer << "\n";

    return 0;
}
