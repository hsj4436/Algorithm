#include <iostream>

#define LL long long

LL A, B;
LL ones[55];

LL get_ones(LL target) {
    LL answer = target & 1;
    for (LL i = 54; i > 0; i--) {
        if (target & (1LL << i)) {
            answer += ones[i - 1] + (target - (1LL << i) + 1);
            target -= (1LL << i);
        }
    }

    return answer;
}

int main() {
    std::cin >> A >> B;

    ones[0] = 1;
    for (LL i = 1; i < 55; i++) {
        ones[i] = 2 * ones[i - 1] + (1LL << i);
    }

    std::cout << get_ones(B) - get_ones(A - 1) << "\n";

    return 0;
}
