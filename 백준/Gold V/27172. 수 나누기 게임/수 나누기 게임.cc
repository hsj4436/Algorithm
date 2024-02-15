#include <iostream>
#include <vector>

int N;
std::vector<int> subs[1000001];
bool is_card[1000001];
int cards[100001];
int scores[1000001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> cards[i];
        is_card[cards[i]] = true;
    }

    for (int i = 1; i < 1000001; i++) {
        if (!is_card[i]) {
            continue;
        }
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                subs[i].push_back(j);
                if (j * j != i) {
                    subs[i].push_back(i / j);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j : subs[cards[i]]) {
            if (is_card[j]) {
                scores[j]++;
                scores[cards[i]]--;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << scores[cards[i]] << " ";
    }

    return 0;
}
