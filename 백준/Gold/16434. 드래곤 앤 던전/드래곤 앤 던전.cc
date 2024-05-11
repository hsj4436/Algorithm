#include <iostream>

#define LL long long

struct room {
    LL t;
    LL a;
    LL h;
    room () {}
    room(LL t, LL a, LL h) : t(t), a(a), h(h) {}
};

LL N;
LL hATK;
room rooms[123457];

bool isPossibleHP(LL hp) {
    LL curATK = hATK;
    LL curHP = hp;
    for (int i = 0; i < N; i++) {
        if (rooms[i].t == 1) {
            LL monsterHP = rooms[i].h;
            LL monsterATK = rooms[i].a;

            LL cycle = 0;
            if (monsterHP % curATK == 0) {
                cycle = monsterHP / curATK - 1;
            } else {
                cycle = monsterHP / curATK;
            }

            curHP -= monsterATK * cycle;
            if (curHP <= 0) {
                return false;
            }
        } else {
            curATK += rooms[i].a;
            curHP = (curHP + rooms[i].h > hp) ? hp : curHP + rooms[i].h;
        }
    }

    return true;
}

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> hATK;

    LL T, A, H;
    for (int i = 0; i < N; i++) {
        std::cin >> T >> A>> H;
        rooms[i] = room(T, A, H);
    }


    LL answer = 1e18;
    LL min = 1, max = answer;
    while (min <= max) {
        LL mid = (min + max) / 2;
        if (isPossibleHP(mid)) {
            answer = mid;
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }

    std::cout << answer << "\n";

    return 0;
}
