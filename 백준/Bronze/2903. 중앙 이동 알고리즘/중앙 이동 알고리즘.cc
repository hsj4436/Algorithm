#include <iostream>

int N;

int main() {
    std::cin >> N;

    int dot_in_row = 2;

    for (int i = 1; i < N + 1; i++) {
        dot_in_row = dot_in_row * 2 - 1;
    }

    std::cout << dot_in_row * dot_in_row << "\n";
    return 0;
}
