#include <iostream>
#include <cstring>

int T, N;
long long price[1000002];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> T;

    for (int tc = 0; tc < T; tc++) {
        std::cin >> N;
        std::memset(price, 0, sizeof(price));
        for (int i = 0; i < N; i++) {
            std::cin >> price[i];
        }
        long long stocks = 0;
        long long profit = 0;
        long long unrealized = 0;
        long long selling_price = 0;
        for (int i = N - 1; i > -1; i--) {
            if (selling_price == 0) {
                selling_price = price[i];
            } else {
                if (selling_price > price[i]) {
                    unrealized += price[i];
                    stocks++;
                } else {
                    profit += stocks * selling_price - unrealized;
                    unrealized = 0;
                    stocks = 0;
                    selling_price = price[i];
                }
            }
        }
        profit += stocks * selling_price - unrealized;
        std::cout << profit << "\n";
    }
    return 0;
}
