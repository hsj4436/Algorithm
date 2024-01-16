#include <iostream>

int H, W, N, M;

int main() {
    std::cin >> H >> W >> N >> M;

    long long row = 1;
    for (int i = 1 + M + 1; i < W + 1;) {
        row++;
        i += M + 1;
    }

    long long col = 1;
    for (int i = 1 + N + 1; i < H + 1;) {
        col++;
        i += N + 1;
    }

    std::cout << row * col << "\n";

    return 0;
}
