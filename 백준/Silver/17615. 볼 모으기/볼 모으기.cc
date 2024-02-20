#include <iostream>

int N;
char str[500001];

int main() {
    std::cin >> N;

    std::cin >> str;

    // move red
    int red_move_count = 0;
    bool streak = true;
    for (int i = N - 1; i > -1; i--) {
        if (str[i] == 'R') {
            if (!streak) {
                red_move_count++;
            }
        } else {
            streak = false;
        }
    }

    int red_move_count2 = 0;
    streak = true;
    for (int i = 0; i < N; i++) {
        if (str[i] == 'R') {
            if (!streak) {
                red_move_count2++;
            }
        } else {
            streak = false;
        }
    }


    int blue_move_count = 0;
    streak = true;
    for (int i = N - 1; i > -1; i--) {
        if (str[i] == 'B') {
            if (!streak) {
                blue_move_count++;
            }
        } else {
            streak = false;
        }
    }

    int blue_move_count2 = 0;
    streak = true;
    for (int i = 0; i < N; i++) {
        if (str[i] == 'B') {
            if (!streak) {
                blue_move_count2++;
            }
        } else {
            streak = false;
        }
    }

    std::cout << std::min(red_move_count, std::min(blue_move_count, std::min(red_move_count2, blue_move_count2))) << "\n";

    return 0;
}
