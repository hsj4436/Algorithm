#include <iostream>

int N, M;
bool opened[21];
int to_open[21];
int answer = 1e9;

void back_track(int index, int moved) {
    if (index == M) {
        answer = std::min(answer, moved);
        return;
    }


    if (opened[to_open[index]]) {
        back_track(index + 1, moved);
        return;
    }
    opened[to_open[index]] = true;
    int left = 1e9;
    for (int j = to_open[index] - 1; j > 0; j--) {
        if (opened[j]) {
            left = to_open[index] - j;
            break;
        }
    }

    if (left != 1e9) {
        opened[to_open[index] - left] = false;
        back_track(index + 1, moved + left);
        opened[to_open[index] - left] = true;
    }

    int right = 1e9;
    for (int j = to_open[index] + 1; j < N + 1; j++) {
        if (opened[j]) {
            right = j - to_open[index];
            break;
        }
    }

    if (right != 1e9) {
        opened[to_open[index] + right] = false;
        back_track(index + 1, moved + right);
        opened[to_open[index] + right] = true;
    }

    opened[to_open[index]] = false;
    return;
}

int main() {
    std::cin >> N;
    int num;
    std::cin >> num;
    opened[num] = true;
    std::cin >> num;
    opened[num] = true;
    std::cin >> M;

    for (int i = 0; i < M; i++) {
        std::cin >> to_open[i];
    }

    back_track(0, 0);

    std::cout << answer << "\n";
    return 0;
}
