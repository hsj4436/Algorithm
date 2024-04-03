#include <iostream>

std::string S;

int main() {
    std::cin >> S;

    int zeros = 0, ones = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '0') {
            zeros++;
        } else {
            ones++;
        }
    }

    int zeroCount = 0, oneCount;
    for (int i = 0; i < S.size(); i++) {
        if (oneCount == ones / 2) {
            break;
        }
        if (S[i] == '1') {
            S.erase(i, 1);
            oneCount++;
            i--;
        }
    }
    for (int i = S.size() - 1; i > -1; i--) {
        if (zeroCount == zeros / 2) {
            break;
        }
        if (S[i] == '0') {
            S.erase(i, 1);
            zeroCount++;
        }
    }

    std::cout << S << "\n";

    return 0;
}
