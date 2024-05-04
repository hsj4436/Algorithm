#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
int minM[101];

int main() {
    std::cin >> N >> M;

    int P, L;
    for (int i = 0; i < N; i++) {
        std::cin >> P >> L;
        std::vector<int> m(P);
        for (int j = 0; j < P; j++) {
            std::cin >> m[j];
        }
        std::sort(m.begin(), m.end(), std::greater<int>());

        while (m.size() > L) {
            m.pop_back();
        }

        if (m.size() == L) {
            minM[i] = m.back();
        } else {
            minM[i] = 1;
        }
    }

    std::sort(minM, minM + N);

    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (minM[i] <= M) {
            M -= minM[i];
            answer++;
        }
    }
    std::cout << answer << "\n";

    return 0;
}
