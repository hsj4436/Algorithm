#include <iostream>

int H, W, X, Y;
int addedArr[601][601];

int main() {
    std::cin >> H >> W >> X >> Y;

    for (int i = 1; i < H + X + 1; i++) {
        for (int j = 1; j < W + Y + 1; j++) {
            std::cin >> addedArr[i][j];
        }
    }

    for (int i = X + 1; i < H + X + 1; i++) {
        for (int j = Y + 1; j < W + Y + 1; j++) {
            if (X + 1 <= i && i < H + 1 && Y + 1 <= j && j < W + 1) {
                addedArr[i][j] -= addedArr[i - X][j - Y];
            } else {
                addedArr[i - X][j - Y] = addedArr[i][j];
            }
        }
    }

    for (int i = 1; i < H + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            std::cout << addedArr[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}