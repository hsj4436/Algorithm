#include <iostream>
#include <vector>

int N, K;
int shuffleIndex[10001];
std::vector<int> origin;

int main() {
    std::cin >> N >> K;

    origin.push_back(-1);
    int card;
    for (int i = 0; i < N; i++) {
        std::cin >> card;
        origin.push_back(card);
    }

    for (int i = 1; i < N + 1; i++) {
        std::cin >> shuffleIndex[i];
    }

    int stepToCycle = 0;
    std::vector<int> beforeShuffle = origin;
    int count = 0;
    for (; count < K; count++) {
        std::vector<int> shuffled(N + 1, -1);
        for (int i = 1; i < N + 1; i++) {
            shuffled[shuffleIndex[i]] = beforeShuffle[i];
        }
        if (shuffled == origin) {
            stepToCycle = count;
            break;
        }
        beforeShuffle = shuffled;
    }

    if (count < K && stepToCycle != 0) {
        count %= stepToCycle;
    }

    for (; count < K; count++) {
        std::vector<int> shuffled(N + 1, -1);
        for (int i = 1; i < N + 1; i++) {
            shuffled[shuffleIndex[i]] = beforeShuffle[i];
        }
        if (shuffled == origin) {
            stepToCycle = K - count;
            break;
        }
        beforeShuffle = shuffled;
    }

    for (int i = 1; i < N + 1; i++) {
        std::cout << beforeShuffle[i] << " ";
    }

    return 0;
}
