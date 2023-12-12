#include <iostream>

int N, d, k, c;
int sushi[30001];
int selected[3001];

int main() {
    std::cin >> N >> d >> k >> c;
    selected[c]++;

    for (int i = 0; i < N; i++) {
        std::cin >> sushi[i];
    }

    int answer = 0;
    int distinct = 1;
    for (int i = 0; i < k; i++) {
        if (selected[sushi[i]] == 0) {
            distinct++;
        }
        selected[sushi[i]]++;
    }

    answer = distinct;

    for (int i = k; i < N + k; i++) {
        selected[sushi[i - k]]--;
        if (selected[sushi[i - k]] == 0) {
            distinct--;
        }
        if (selected[sushi[i % N]] == 0) {
            distinct++;
        }
        selected[sushi[i % N]]++;
        answer = std::max(answer, distinct);
    }

    std::cout << answer << "\n";

    return 0;
}
