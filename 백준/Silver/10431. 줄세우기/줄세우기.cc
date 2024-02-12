#include <iostream>

int P;
int heights[21];

int main() {
    std::cin >> P;

    for (int tc = 1; tc < P + 1; tc++) {
        std::cin >> tc;
        for (int i = 1; i < 21; i++) {
            std::cin >> heights[i];
        }

        int count = 0;
        for (int i = 2; i < 21; i++) {
            int current_height = heights[i];
            int taller_index = -1;
            for (int j = 1; j < i; j++) {
                if (heights[j] > current_height) {
                    taller_index = j;
                    break;
                }
            }
            if (taller_index != -1) {
                for (int j = i; j >= taller_index; j--) {
                    heights[j] = heights[j - 1];
                }
                heights[taller_index] = current_height;
                count += i - taller_index;
            }
        }

        std::cout << tc << " " << count << "\n";
    }

    return 0;
}