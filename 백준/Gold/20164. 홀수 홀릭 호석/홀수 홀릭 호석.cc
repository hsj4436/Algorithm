#include <iostream>
#include <queue>

std::string N;
int minAnswer = 1000000001;
int maxAnswer = 0;

int main() {
    std::cin >> N;

    std::queue<std::pair<std::string, int>> q;
    int odds = 0;
    for (char ch : N) {
        if ((ch - '0') % 2 != 0) {
            odds++;
        }
    }
    q.push({N, odds});

    while (!q.empty()) {
        std::string cur = q.front().first;
        int seenOdds = q.front().second;
        q.pop();

        if (cur.size() == 1) {
            minAnswer = std::min(minAnswer, seenOdds);
            maxAnswer = std::max(maxAnswer, seenOdds);
        } else if (cur.size() == 2) {
            std::string next = std::to_string((cur[0] - '0') + (cur[1] - '0'));
            odds = 0;
            for (char ch : next) {
                if ((ch - '0') % 2 != 0) {
                    odds++;
                }
            }
            q.push({next, seenOdds + odds});
        } else {
            for (int i = 1; i <= cur.size() - 2; i++) {
                for (int j = 1; j <= cur.size() - i - 1; j++) {
                    std::string left = cur.substr(0, i);
                    std::string mid = cur.substr(i, j);
                    std::string right = cur.substr(i + j);
                    std::string next = std::to_string(std::stoi(left) + std::stoi(mid) + std::stoi(right));
                    odds = 0;
                    for (char ch : next) {
                        if ((ch - '0') % 2 != 0) {
                            odds++;
                        }
                    }
                    q.push({next, seenOdds + odds});
                }
            }
        }
    }

    std::cout << minAnswer << " " << maxAnswer << "\n";

    return 0;
}
