#include <iostream>

int N;
bool balls[500001]; // true - red, false - blue

int main() {
    std::cin >> N;

    char color;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> color;
        if (color == 'R') {
            balls[i] = true;
        }
    }

    // move red
    int red_move_count = 0;
    int first_red_index = -1;
    for (int i = N; i > 0; i--) {
        if (balls[i]) {
            if (first_red_index == -1) {
                first_red_index = i;
                if (i != N) {
                    red_move_count++;
                }
            } else {
                if (first_red_index - 1 == i) {
                    first_red_index = i;
                } else {
                    red_move_count++;
                }
            }
        }
    }

    int blue_move_count = 0;
    int first_blue_index = -1;
    for (int i = N; i > 0; i--) {
        if (!balls[i]) {
            if (first_blue_index == -1) {
                first_blue_index = i;
                if (i != N) {
                    blue_move_count++;
                }
            } else {
                if (first_blue_index - 1 == i) {
                    first_blue_index = i;
                } else {
                    blue_move_count++;
                }
            }
        }
    }

    std::cout << std::min(red_move_count, blue_move_count) << "\n";

    return 0;
}
