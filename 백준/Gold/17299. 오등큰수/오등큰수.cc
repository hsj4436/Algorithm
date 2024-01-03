#include <iostream>
#include <stack>

int N;
int arr[1000001];
int cnt[1000001];

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> arr[i];
        cnt[arr[i]]++;
    }

    std::stack<int> answer;
    std::stack<std::pair<int, int>> stk;
    for (int i = N; i > 0; i--) {
        if (stk.empty()) {
            answer.push(-1);
            stk.push({arr[i], cnt[arr[i]]});
        } else {
            while (!stk.empty()) {
                if (stk.top().second > cnt[arr[i]]) {
                    break;
                } else {
                    stk.pop();
                }
            }
            if (stk.empty()) {
                answer.push(-1);
                stk.push({arr[i], cnt[arr[i]]});
            } else {
                answer.push(stk.top().first);
                stk.push({arr[i], cnt[arr[i]]});
            }
        }
    }

    while (!answer.empty()) {
        std::cout << answer.top() << " ";
        answer.pop();
    }
    return 0;
}
