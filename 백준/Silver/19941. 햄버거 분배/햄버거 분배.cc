#include <iostream>

int N, K;
std::string desk;
bool checked[20001];

int main() {
    std::cin >> N >> K;
    std::cin >> desk;

    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (desk[i] == 'H' && !checked[i]) {
            for (int j = i + 1; j < i + K + 1; j++) {
                if (!checked[j] && desk[j] == 'P') {
                    checked[j] = true;
                    checked[i] = true;
                    answer++;
                    break;
                }
            }
        } else {
            if (!checked[i]) {
                for (int j = std::max(0, i - K); j < std::min(N, i + K + 1); j++) {
                    if (!checked[j] && desk[j] == 'H') {
                        checked[j] = true;
                        checked[i] = true;
                        answer++;
                        break;
                    }
                }
            }
        }
    }

    std::cout << answer << "\n";
    return 0;
}
