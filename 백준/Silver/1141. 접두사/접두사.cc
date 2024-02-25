#include <iostream>
#include <algorithm>

int N;
std::string words[51];
bool X[51];

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> words[i];
        X[i] = true;
    }

    std::sort(words, words + N);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (words[j].substr(0, words[i].size()) == words[i]) {
                X[i] = false;
                break;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (X[i]) {
            answer++;
        }
    }

    std::cout << answer << "\n";

    return 0;
}
