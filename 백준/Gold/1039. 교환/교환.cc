#include <iostream>
#include <queue>

int N, K;
int finalStep[10000000];

int main() {
    std::cin >> N >> K;

    if (N < 10 || (10 <= N && N < 100 && N % 10 == 0)) {
        std::cout << "-1\n";
        return 0;
    }

    finalStep[N] = 0;
    if (K % 2 == 0) {
        finalStep[N] = K;
    } else {
        finalStep[N] = K - 1;
    }

    std::queue<std::pair<int, int>> q;
    q.push({N, 0});
    while (!q.empty()) {
        int cur = q.front().first;
        int step = q.front().second;
        q.pop();

        if (step == K) {
            finalStep[cur] = K;
            continue;
        }

        std::string curString = std::to_string(cur);
        for (int i = 0; i < curString.size(); i++) {
            for (int j = i + 1; j < curString.size(); j++) {
                if (i == 0 && curString[j] == '0') {
                    continue;
                }
                std::swap(curString[i], curString[j]);
                if (finalStep[std::stoi(curString)] == K) {
                    std::swap(curString[i], curString[j]);
                    continue;
                }
                if ((K - step - 1) % 2 == 0) {
                    finalStep[std::stoi(curString)] = K;
                }
                q.push({std::stoi(curString), step + 1});
                std::swap(curString[i], curString[j]);
            }
        }
    }

    int answer = 0;
    for (int i = 1; i < 10000000; i++) {
        if (finalStep[i] == K) {
            answer = i;
        }
    }
    std::cout << answer << "\n";

    return 0;
}
