#include <iostream>
#include <math.h>

#define LL long long

LL L, W, H;
LL N;
LL cubes[20] = {0, };
LL answer = 0;
bool possible = true;

void sol(LL curL, LL curW, LL curH) {
    if (!possible) {
        return;
    }
    if (curL == 0 || curW == 0 || curH == 0) {
        return;
    }

    LL len = 0;
    bool foundCube = false;
    int index = 0;
    LL minLength = std::min(curL, std::min(curW, curH));
    for (int i = 19; i > -1; i--) {
//        len = (LL)std::pow(2, (LL)i);
        len = 1LL << i;
        if (cubes[i] > 0 && len <= minLength) {
            index = i;
            foundCube = true;
            break;
        }
    }
    if (!foundCube) {
        possible = false;
        return;
    }

    cubes[index]--;
    answer++;

    sol(curL - len, curW, curH);
    sol(len, curW - len, curH);
    sol(len, len, curH - len);

    return;
}

int main() {
    std::cin >> L >> W >> H;

    std::cin >> N;

    LL a, b;
    for (int i = 0; i < N; i++) {
        std::cin >> a >> b;
        cubes[a] = b;
    }

    sol(L, W, H);
    if (!possible) {
        std::cout << "-1\n";
    } else {
        std::cout << answer << "\n";
    }

    return 0;
}
