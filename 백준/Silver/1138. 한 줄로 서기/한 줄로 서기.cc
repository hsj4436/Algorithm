#include <iostream>

int N;
int left[11];
bool selected[11];
int aligned[11];

bool back_track(int count) {
    if (count == N + 1) {
        for (int i = 1; i < N + 1; i++) {
            std::cout << aligned[i] << " ";
        }
        return true;
    }

    for (int i = 1; i < N + 1; i++) {
        if (selected[i]) {
            continue;
        }
        int bigger = 0;
        for (int j = 1; j < count; j++) {
            if (aligned[j] > i) {
                bigger++;
            }
        }
        if (bigger == left[i]) {
            aligned[count] = i;
            selected[i] = true;
            if (back_track(count + 1)) {
                return true;
            }
            selected[i] = false;
            aligned[count] = 0;
        }
    }
}

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> left[i];
    }

    back_track(1);

    return 0;
}
