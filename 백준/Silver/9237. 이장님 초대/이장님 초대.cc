#include <iostream>
#include <algorithm>

int N;
int trees[100001];

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> trees[i];
    }

    std::sort(trees, trees + N, [&](int a, int b) {return a > b;});

    int answer = 0;
    for (int i = 0; i < N; i++) {
        int this_end = i + 1 + trees[i];
        answer = std::max(answer, this_end);
    }

    std::cout << answer + 1 << "\n";
    
    return 0;
}
