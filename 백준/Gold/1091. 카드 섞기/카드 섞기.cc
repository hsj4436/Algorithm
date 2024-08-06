#include <iostream>
#include <vector>

int N;
int P[48];
int S[48];
std::vector<int> cards;

bool isEnd() {
    for (int i = 0; i < N; i++) {
        if (P[cards[i]] != i % 3) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cin >> N;

    int p;
    for (int i = 0; i < N; i++) {
        std::cin >> p;
        P[i] = p;
    }

    int s;
    for (int i = 0; i < N; i++) {
        std::cin >> s;
        S[i] = s;
    }

    for (int i = 0; i < N; i++) {
        cards.push_back(i);
    }

    int counter = 0;
    while (!isEnd()) {
        std::vector<int> temp(N, 0);
        for (int i = 0; i < N; i++) {
            temp[S[i]] = cards[i];
        }

        cards = temp;

        if (counter > 0) {
            bool isOrigin = true;
            for (int i = 0; i < N; i++) {
                if (cards[i] != i) {
                    isOrigin = false;
                    break;
                }
            }
            if (isOrigin) {
                std::cout << "-1\n";
                return 0;
            }
        }

        counter++;
    }

    std::cout << counter << "\n";

    return 0;
}
