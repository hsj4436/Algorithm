#include <iostream>

int N, H;
int evenHeight[500002];
int oddHeight[500002];
int obstacle[200001];

int main() {
    std::cin >> N >> H;

    int h = 0;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> h;
        if (i % 2 == 0) {
            evenHeight[H + 1 - h]++;
        } else {
            oddHeight[h]++;
        }
    }

    for (int i = 1; i < H + 1; i++) {
        evenHeight[i] += evenHeight[i - 1];
        oddHeight[H + 1 - i] += oddHeight[H + 2 - i];
    }

    for (int i = 1; i < H + 1; i++) {
        obstacle[evenHeight[i] + oddHeight[i]]++;
    }

    int minObstacle = 0;
    int numberOfSection = 0;
    for (int i = 0; i < N + 1; i++) {
        if (obstacle[i] != 0) {
            minObstacle = i;
            numberOfSection = obstacle[i];
            break;
        }
    }

    std::cout << minObstacle << " " << numberOfSection << "\n";

    return 0;
}
