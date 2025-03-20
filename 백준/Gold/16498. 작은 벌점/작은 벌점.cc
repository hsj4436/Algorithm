#include <iostream>
#include <algorithm>

int A, B, C;
int As[1001];
int Bs[1001];
int Cs[1001];

int main() {
    std::cin >> A >> B >> C;

    for (int i = 0; i < A; i++) {
        std::cin >> As[i];
        As[i] += 100000000;
    }
    for (int i = 0; i < B; i++) {
        std::cin >> Bs[i];
        Bs[i] += 100000000;
    }
    for (int i = 0; i < C; i++) {
        std::cin >> Cs[i];
        Cs[i] += 100000000;
    }

    std::sort(As, As + A);
    std::sort(Bs, Bs + B);
    std::sort(Cs, Cs + C);

    int answer = 200000001;

    for (int i = 0; i < A; i++) {
        int left = 0, right = B - 1;
        int b = Bs[(left + right) / 2];
        while (left <= right) {
            int mid = (left + right) / 2;
            if (Bs[mid] == As[i]) {
                b = Bs[mid];
                break;
            } else if (Bs[mid] < As[i]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (std::abs(As[i] - b) > std::abs(As[i] - Bs[mid])) {
                b = Bs[mid];
            }
        }

        left = 0, right = C - 1;
        int c1 = Cs[(left + right) / 2];
        while (left <= right) {
            int mid = (left + right) / 2;
            if (Cs[mid] == As[i]) {
                c1 = Cs[mid];
                break;
            } else if (Cs[mid] < As[i]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (std::abs(As[i] - c1) > std::abs(As[i] - Cs[mid])) {
                c1 = Cs[mid];
            }
        }

        left = 0, right = C - 1;
        int c2 = Cs[(left + right) / 2];
        while (left <= right) {
            int mid = (left + right) / 2;
            if (Cs[mid] == b) {
                c2 = Cs[mid];
                break;
            } else if (Cs[mid] < b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (std::abs(b - c2) > std::abs(b - Cs[mid])) {
                c2 = Cs[mid];
            }
        }

        int score = std::max(As[i], std::max(b, c1)) - std::min(As[i], std::min(b, c1));
        answer = std::min(answer, score);

        score = std::max(As[i], std::max(b, c2)) - std::min(As[i], std::min(b, c2));
        answer = std::min(answer, score);
    }

    std::cout << answer << "\n";

    return 0;
}
