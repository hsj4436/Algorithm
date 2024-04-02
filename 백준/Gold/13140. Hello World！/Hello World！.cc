#include <iostream>

#define MAX_INDEX 7

int N;
bool end = false;
bool selected[10];
int assigned[MAX_INDEX]; // d, e, h, l, o, r, w

int getHello() {
    int result = assigned[2];
    result *= 10;
    result += assigned[1];
    result *= 10;
    result += assigned[3];
    result *= 10;
    result += assigned[3];
    result *= 10;
    result += assigned[4];

    return result;
}

int getWorld() {
    int result = assigned[6];
    result *= 10;
    result += assigned[4];
    result *= 10;
    result += assigned[5];
    result *= 10;
    result += assigned[3];
    result *= 10;
    result += assigned[0];

    return result;
}

void combinations(int index) {
    if (index == MAX_INDEX) {
        int hello = getHello();
        int world = getWorld();
        if (hello + world == N && !end) {
            end = true;
            std::cout << "  " << hello << "\n" << "+ " << world << "\n" << "-------" << "\n";
            if (N >= 100000) {
                std::cout << " " << N << "\n";
            } else {
                std::cout << "  " << N << "\n";
            }
        }
        return;
    }

    if (end) {
        return;
    }
    for (int i = 0; i < 10; i++) {
        if ((index == 2 || index == 6) && i == 0) {
            continue;
        }
        if (selected[i]) {
            continue;
        }
        selected[i] = true;
        assigned[index] = i;
        combinations(index + 1);
        if (end) {
            return;
        }
        assigned[index] = 0;
        selected[i] = false;
    }
}


int main() {
    std::cin >> N;

    combinations(0);

    if (!end) {
        std::cout << "No Answer\n";
    }

    return 0;
}
