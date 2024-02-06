#include <iostream>
#include <vector>
#include <sstream>

#define LL long long

int N, M, H;
std::vector<LL> blocks[51];
LL dp[51][1001];

int main() {
    std::cin >> N >> M >> H;
    std::cin.ignore();
    for (int i = 1; i < N + 1; i++) {
        std::string input;
        std::getline(std::cin, input);
        std::stringstream sstr(input);
        LL tmp = 0;
        while (sstr >> tmp) {
            blocks[i].push_back(tmp);
        }
    }

    for (int i = 0; i < N + 1; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < H + 1; j++) {
            for (LL height : blocks[i]) {
                if (j >= height) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - height]) % 10007;
                }
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 10007;
        }
    }

    std::cout << dp[N][H] << "\n";
    return 0;
}