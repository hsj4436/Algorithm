#include <iostream>
#include <queue>
#include <set>

std::string N;
int K;

int main() {
    std::cin >> N >> K;

    if (N.size() == 1 || (N.size() == 2 && N[1] == 0)) {
        std::cout << "-1\n";
        return 0;
    }

    std::queue<std::string> Q;
    Q.push(N);
    for (int k = 0; k < K; k++) {
        int queueSize = Q.size();
        std::set<std::string> visited;

        for (int q = 0; q < queueSize; q++) {
            std::string cur = Q.front();
            Q.pop();

            if (visited.count(cur) != 0) {
                continue;
            }
            visited.insert(cur);

            for (int i = 0; i < N.size(); i++) {
                for (int j = i + 1; j < N.size(); j++) {
                    if (i == 0 && cur[j] == '0') {
                        continue;
                    }
                    std::swap(cur[i], cur[j]);
                    Q.push(cur);
                    std::swap(cur[i], cur[j]);
                }
            }
        }
    }

    std::string answer = "0";
    while (!Q.empty()) {
        answer = std::max(answer, Q.front());
        Q.pop();
    }

    if (answer[0] == '0') {
        std::cout << "-1\n";
    } else {
        std::cout << answer << "\n";
    }

    return 0;
}
