#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int, int>> q;
    for (int i = 0; i < speeds.size(); i++) {
        q.push({progresses[i], speeds[i]});
    }
    int days = 0;
    while (!q.empty()) {
        if (days == 0) {
            if ((100 - q.front().first) % q.front().second == 0) {
                days += (100 - q.front().first) / q.front().second;
            } else {
                days += (100 - q.front().first) / q.front().second + 1;
            }
        } else {
            if ((100 - q.front().first - q.front().second * days) % q.front().second == 0) {
                days += (100 - q.front().first - q.front().second * days) / q.front().second;
            } else {
                days += (100 - q.front().first - q.front().second * days) / q.front().second + 1;
            }
        }
        int count = 0;
        while (!q.empty() && days * q.front().second + q.front().first >= 100) {
            q.pop();
            count++;
        }
        answer.push_back(count);
    }
    return answer;
}