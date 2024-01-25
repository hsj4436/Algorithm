#include <iostream>
#include <map>

#define PII std::pair<int, int>

int N, K;
int order[101];
int tab[101];

int main() {
    std::cin >> N >> K;

    for (int i = 0; i < K; i++) {
        std::cin >> order[i];
    }

    int cnt = 0;
    for (int i = 0; i < K; i++) {
        bool plugged = false;
        for (int j = 0; j < N; j++) {
            if (order[i] == tab[j]) {
                plugged = true;
                break;
            }
        }

        if (plugged) {
            continue;
        }

        for (int j = 0; j < N; j++) {
            if (tab[j] == 0) {
                tab[j] = order[i];
                plugged = true;
                break;
            }
        }

        if (plugged) {
            continue;
        }

        int position = -1, index = -1;
        for (int j = 0; j < N; j++) {
            int tmp = 0;
            for (int k = i + 1; k < K; k++) {
                if (tab[j] == order[k]) {
                    break;
                }
                tmp++;
            }
            if (tmp > index) {
                position = j;
                index = tmp;
            }
        }
        tab[position] = order[i];
        cnt++;
    }

    std::cout << cnt << "\n";

    return 0;
}