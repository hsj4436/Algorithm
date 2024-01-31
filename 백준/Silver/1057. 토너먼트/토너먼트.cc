#include <iostream>

int N;
int KJM, IHS;


int main() {
    std::cin >> N >> KJM >> IHS;

    if (KJM > IHS) {
        std::swap(KJM, IHS);
    }

    int round = 1;
    while (true) {
        if (KJM % 2 == 1 && KJM + 1 == IHS) {
            break;
        }
        if (KJM % 2 == 0) {
            KJM /= 2;
        } else {
            KJM = KJM / 2 + 1;
        }
        if (IHS % 2 == 0) {
            IHS /= 2;
        } else {
            IHS = IHS / 2 + 1;
        }
        round++;
    }

    std::cout << round << "\n";
    return 0;
}
