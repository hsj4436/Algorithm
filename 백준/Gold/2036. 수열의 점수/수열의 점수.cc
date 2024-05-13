#include <iostream>
#include <algorithm>

#define LL long long

int N;
LL negatives[100001];
LL positives[100001];

int main() {
    std::cin >> N;

    int n;
    int nIndex = 0, pIndex = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> n;
        if (n <= 0) {
            negatives[nIndex] = n;
            nIndex++;
        } else if (n > 0) {
            positives[pIndex] = n;
            pIndex++;
        }
    }

    std::sort(negatives, negatives + nIndex);
    std::sort(positives, positives + pIndex);

    LL answer = 0;
    if (nIndex % 2 == 0) {
        for (int i = 0; i < nIndex; i += 2) {
            answer += negatives[i] * negatives[i + 1];
        }
    } else {
        for (int i = 0; i < nIndex - 1; i += 2) {
            answer += negatives[i] * negatives[i + 1];
        }
        answer += negatives[nIndex - 1];
    }
    for (int i = pIndex - 1; i > -1; i--) {
        if (positives[i] == 1 || (i - 1 >= 0 && positives[i - 1] == 1)) {
            answer += positives[i];
            continue;
        }
        if (i - 1 >= 0 && positives[i] * positives[i - 1] > positives[i] + positives[i - 1]) {
            answer += positives[i] * positives[i - 1];
            i--;
        } else {
            answer += positives[i];
        }
    }

    std::cout << answer << "\n";

    return 0;
}
