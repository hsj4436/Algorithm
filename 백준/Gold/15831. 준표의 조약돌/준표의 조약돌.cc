#include <iostream>

int N;
int B, W;
std::string road;

int main() {
    std::cin >> N >> B >> W;

    std::cin >> road;

    int answer = 0;
    int black = 0, white = 0;
    int left = 0, right = 0;
    for (; right < N; right++) {
        if (road[right] == 'B') {
            black++;
        } else {
            white++;
        }
        if (black > B) {
            while (black > B && left <= right) {
                if (road[left] == 'B') {
                    black--;
                } else {
                    white--;
                }
                left++;
            }
        }
        if (white >= W) {
            answer = std::max(answer, right - left + 1);
        }
    }

    std::cout << answer << "\n";

    return 0;
}
