#include <iostream>

int main() {
    int N, K;
    std::cin >> N >> K;

    int answer = -1;
    int index = 0;
    for (int i = 1; i < N + 1; i++) {
        if (N % i == 0) {
            index++;
            if (index == K) {
                answer = i;
                break;
            }
        }
    }

    std::cout << ((answer == -1) ? 0 : answer) << "\n";
    return 0;
}
