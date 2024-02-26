#include <iostream>

int N;
int temperature[5001];
int dp[5001][10][10][10];

int sol(int index, int x, int y, int z) {
    if (index == N) {
        return 0;
    }
    if (dp[index][x][y][z] != -1) {
        return dp[index][x][y][z];
    }

    int result = (int)1e9;
    result = std::min(result, sol(index + 1, temperature[index + 1], y, z) + std::min(std::abs(x - temperature[index + 1]), 10 - std::abs(x - temperature[index + 1])));
    result = std::min(result, sol(index + 1, x, temperature[index + 1], z) + std::min(std::abs(y - temperature[index + 1]), 10 - std::abs(y - temperature[index + 1])));
    result = std::min(result, sol(index + 1, x, y, temperature[index + 1]) + std::min(std::abs(z - temperature[index + 1]), 10 - std::abs(z - temperature[index + 1])));
    dp[index][x][y][z] = result;
    return result;
}

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> temperature[i];
    }
    std::fill_n(&dp[0][0][0][0], 5001 * 10 * 10 * 10, -1);

    std::cout << sol(0, 0, 0, 0) << "\n";
    return 0;
}
