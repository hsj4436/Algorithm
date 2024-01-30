#include <iostream>
#include <algorithm>

int N, M;
int cake[1001];

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> cake[i];
    }

    std::sort(cake, cake + N, [&](int a, int b) {
        if (a % 10 == b % 10) {
            return a < b;
        } else {
            return (a % 10 == 0);
        }
    });

    int cnt = 0, cakes = 0;
    bool end = false;
    for (int i = 0; i < N; i++) {
        int length = cake[i];
        if (length == 10) {
            cakes++;
            continue;
        }
        if (end) {
            continue;
        }
        while (length > 10) {
            length -= 10;
            cakes++;
            cnt++;
            if (cnt == M) {
                end = true;
                break;
            }
        }
        if (length == 10) {
            cakes++;
        }
    }

    std::cout << cakes << "\n";

    return 0;
}
