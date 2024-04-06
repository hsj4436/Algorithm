#include <iostream>

int N;
std::string first;
int firstCount[27] = {0, };

int main() {
    std::cin >> N;
    std::cin >> first;
    for (char ch : first) {
        firstCount[ch - 'A']++;
    }

    int answer = 0;
    std::string word;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> word;
        int count[27] = {0, };
        for (char ch : word) {
            count[ch - 'A']++;
        }
        bool isSimilar = true;
        if (first.size() == word.size()) {
            int minus = 0, plus = 0;
            for (int j = 0; j < 27; j++) {
                if (std::abs(count[j] - firstCount[j]) >= 2) {
                    isSimilar = false;
                    break;
                }
                if (count[j] - firstCount[j] == -1) {
                    minus++;
                } else if (count[j] - firstCount[j] == 1) {
                    plus++;
                }
            }
            if (minus != 0 || plus != 0) {
                if (!(minus == 1 && plus == 1)) {
                    isSimilar = false;
                }
            }
        } else if (first.size() < word.size()) {
            int plus = 0;
            for (int j = 0; j < 27; j++) {
                if (count[j] - firstCount[j] < 0) {
                    isSimilar = false;
                    break;
                }
                if (count[j] - firstCount[j] > 0) {
                    plus += count[j] - firstCount[j];
                }
            }
            if (plus > 1) {
                isSimilar = false;
            }
        } else {
            int minus = 0;
            for (int j = 0; j < 27; j++) {
                if (count[j] - firstCount[j] > 0) {
                    isSimilar = false;
                    break;
                }
                if (count[j] - firstCount[j] < 0) {
                    minus += count[j] - firstCount[j];
                }
            }
            if (minus < -1) {
                isSimilar = false;
            }
        }
        if (isSimilar) {
            answer++;
        }
    }

    std::cout << answer << "\n";

    return 0;
}