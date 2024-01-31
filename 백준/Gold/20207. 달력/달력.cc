#include <iostream>

int N;
int S, E;
int calender[366];

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> S >> E;
        for (int j = S; j < E + 1; j++) {
            calender[j]++;
        }
    }

    int answer = 0;
    int length = 0, height = 0;
    for (int i = 1; i < 366; i++) {
        if (calender[i] != 0) {
            length++;
            height = std::max(height, calender[i]);
        } else {
            answer += length * height;
            length = 0;
            height = 0;
        }
    }
    
    if (length != 0 && height != 0) {
        answer += length * height;
    }

    std::cout << answer << "\n";

    return 0;
}