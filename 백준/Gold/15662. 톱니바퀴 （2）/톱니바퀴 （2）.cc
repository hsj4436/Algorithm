#include <iostream>
#include <vector>

#define PII std::pair<int, int>

int T, K;
int wheel[1002][8];
int head[1002] = {0, };

int main() {
    std::cin >> T;

    for (int i = 1; i < T + 1; i++) {
        std::string state;
        std::cin >> state;
        for (int j = 0; j < state.size(); j++) {
            wheel[i][j] = state[j] - '0';
        }
    }

    std::cin >> K;

    int which, direction;
    for (int i = 0; i < K; i++) {
        std::cin >> which >> direction;

        if (T == 1) {
            if (direction == 1) {
                head[which] = (head[which] + 7) % 8;
            } else {
                head[which] = (head[which] + 1) % 8;
            }
            continue;
        }

        int left_d = direction * -1, right_d = direction * -1;
        std::vector<PII> left; // {index, direction}
        for (int j = which - 1; j > 0; j--) {
            if (wheel[j][(head[j] + 2) % 8] != wheel[j + 1][(head[j + 1] + 6) % 8]) {
                left.push_back({j, left_d});
                left_d *= -1;
            } else {
                break;
            }
        }
        for (auto p : left) {
            if (p.second == 1) {
                head[p.first] = (head[p.first] + 7) % 8;
            } else {
                head[p.first] = (head[p.first] + 1) % 8;
            }
        }
        std::vector<PII> right;
        for (int j = which + 1; j < T + 1; j++) {
            if (wheel[j][(head[j] + 6) % 8] != wheel[j - 1][(head[j - 1] + 2) % 8]) {
                right.push_back({j, right_d});
                right_d *= -1;
            } else {
                break;
            }
        }
        for (auto p : right) {
            if (p.second == 1) {
                head[p.first] = (head[p.first] + 7) % 8;
            } else {
                head[p.first] = (head[p.first] + 1) % 8;
            }
        }
        if (direction == 1) {
            head[which] = (head[which] + 7) % 8;
        } else {
            head[which] = (head[which] + 1) % 8;
        }
    }

    int answer = 0;
    for (int i = 1; i < T + 1; i++) {
        if (wheel[i][head[i] % 8] == 1) {
            answer++;
        }
    }
    std::cout << answer << "\n";

    return 0;
}