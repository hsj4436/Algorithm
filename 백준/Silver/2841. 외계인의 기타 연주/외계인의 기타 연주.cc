#include <iostream>
#include <stack>

#define PII std::pair<int, int>

int N, P;
std::stack<int> finger[7];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> P;

    int answer = 0;
    int line, prat;
    for (int i = 0; i < N; i++) {
        std::cin >> line >> prat;
        if (finger[line].empty()) {
            answer++;
            finger[line].push(prat);
        } else {
            if (finger[line].top() > prat) {
                int cnt = 0;
                while (!finger[line].empty()) {
                    if (finger[line].top() <= prat) {
                        break;
                    }
                    cnt++;
                    finger[line].pop();
                }
                if (finger[line].empty()) {
                    answer += cnt + 1;
                    finger[line].push(prat);
                } else if (finger[line].top() < prat) {
                    answer += cnt + 1;
                    finger[line].push(prat);
                } else {
                    answer += cnt;
                }
            } else if (finger[line].top() < prat) {
                finger[line].push(prat);
                answer++;
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}