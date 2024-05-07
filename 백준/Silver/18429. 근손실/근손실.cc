#include <iostream>
#include <algorithm>

int N, K;
int weights[8];
bool selected[8];
int answer = 0;

void sol(int day, int power) {
    if (day == N) {
        if (power >= 500) {
            answer++;
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (selected[i]) {
            continue;
        }
        if (power + weights[i] - K >= 500) {
            selected[i] = true;
            sol(day + 1, power + weights[i] - K);
            selected[i] = false;
        }
    }
}

int main() {
    std::cin >> N >> K;

    for (int i = 0; i < N; i++) {
        std::cin >> weights[i];
    }

    sol(0, 500);

    std::cout << answer << "\n";
    return 0;
}
