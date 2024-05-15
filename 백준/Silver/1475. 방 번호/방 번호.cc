#include <iostream>

std::string number;
int counts[10];

int main() {
    std::cin >> number;

    for (char ch : number) {
        counts[ch - '0']++;
    }

    int answer = ((counts[6] + counts[9]) % 2 == 0) ? (counts[6] + counts[9]) / 2 : (counts[6] + counts[9]) / 2 + 1;
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) {
            continue;
        }
        answer = std::max(answer, counts[i]);
    }

    std::cout << answer << "\n";

    return 0;
}
