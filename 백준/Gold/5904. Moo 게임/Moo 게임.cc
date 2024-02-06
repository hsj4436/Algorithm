#include <iostream>

int N;
// S0 - 3
// S1 - (3) + 4 + (3)
// S2 - (3 + 4 + 3) + 5 + (3 + 4 + 3)
int S_size[500];
std::string MOO = "moo";

void back_track(int moo_size, int k, int start_index) {
    if (k == 0) {
        if (N == start_index) {
            std::cout << "m" << "\n";
            return;
        } else {
            std::cout << "o" << "\n";
            return;
        }
    }
    int left_start = start_index;
    int moo_start = start_index + S_size[k - 1];
    int right_start = start_index + S_size[k - 1] + moo_size;

    if (N < moo_start) {
        back_track(moo_size - 1, k - 1, start_index);
    } else if (N >= moo_start && N < right_start) {
        back_track(moo_size - 1, k - 1, moo_start);
    } else {
        back_track(moo_size - 1, k - 1, right_start);
    }
}

int main() {
    std::cin >> N;

    int length = 3;
    int moo = 3;
    int k = 0;
    S_size[0] = length;
    while (length < N) {
        k++;
        moo++;
        length = 2 * length + moo;
        S_size[k] = length;
    }

    back_track(moo, k, 1);

    return 0;
}
