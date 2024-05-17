#include <iostream>

int main() {
    int score;
    int S = 0, T = 0;
    for (int i = 0; i < 4; i++) {
        std::cin >> score;
        S += score;
    }
    for (int i = 0; i < 4; i++) {
        std::cin >> score;
        T += score;
    }

    printf("%d\n", (S == T ? S : T) < S ? S : T);

    return 0;
}
