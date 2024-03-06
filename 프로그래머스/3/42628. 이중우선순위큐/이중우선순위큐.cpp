#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    deque<int> dq;
    for (string op : operations) {
        if (op[0] == 'I') {
            int number = stoi(op.substr(2));
            dq.push_back(number);
            sort(dq.begin(), dq.end());
        } else if (op[0] == 'D') {
            int number = stoi(op.substr(2));
            if (number == 1) {
                if (!dq.empty()) {
                    dq.pop_back();
                }
            } else {
                if (!dq.empty()) {
                    dq.pop_front();
                }
            }
        }
    }
    
    if (dq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }

    return answer;
}