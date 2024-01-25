#include <iostream>
#include <algorithm>

std::string N;

int main() {
    std::cin >> N;

    std::sort(N.begin(), N.end(), [&](char a, char b) {return a > b;});

    std::string answer;
    do {
        int res = 0;
        for (int i = 0; i < N.size(); i++) {
            res = (res * 10 + (N[i] - '0')) % 30;
        }
        if (res == 0) {
            answer = std::max(answer, N);
        }
    } while (std::next_permutation(N.begin(), N.end()));

    if (answer.empty()) {
        std::cout << "-1\n";
    } else {
        std::cout << answer << "\n";
    }

    return 0;
}