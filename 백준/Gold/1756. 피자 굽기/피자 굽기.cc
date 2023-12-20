#include <iostream>
#include <vector>
#include <algorithm>

int D, N;
std::vector<int> oven;
std::vector<int> pizzas;

int main() {
    std::cin >> D >> N;

    int diameter;
    std::cin >> diameter;
    oven.push_back(diameter);

    for (int i = 1; i < D; i++) {
        std::cin >> diameter;
        oven.push_back(std::min(diameter, oven[i - 1]));
    }

    for (int i = 0; i < N; i++) {
        int pizza = 0;
        std::cin >> pizza;
        pizzas.push_back(pizza);
    }

    int pizza_index = 0;
    int answer = D;
    for (int i = D - 1; i > -1; i--) {
        if (oven[i] >= pizzas[pizza_index]) {
            answer = i + 1;
            pizza_index++;
        }

        if (pizza_index == N) {
            break;
        }
    }

    if (pizza_index == N) {
        std::cout << answer << "\n";
    } else {
        std::cout << "0\n";
    }

    return 0;
}
