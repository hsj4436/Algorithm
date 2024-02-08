#include <iostream>

int N;
std::string words[20001];

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> words[i];
    }

    int length = -1;
    int index_left = 0, index_right = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int temporal_length = 0;
            for (int k = 0; k < std::min(words[i].size(), words[j].size()); k++) {
                if (words[i][k] == words[j][k]) {
                    temporal_length++;
                } else {
                    break;
                }
            }
            if (temporal_length > length) {
                length = temporal_length;
                index_left = i;
                index_right = j;
            }
        }
    }

    std::cout << words[index_left] << "\n" << words[index_right] << "\n";

    return 0;
}