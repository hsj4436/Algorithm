#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    deque<pair<int, int>> dq;
    dq.push_back({1, truck_weights[0]});
    int weightSum = truck_weights[0];
    answer = 2;
    for (int i = 1; i < truck_weights.size(); i++) {
        while (!dq.empty()) {
            if (dq.front().first + bridge_length == answer) {
                weightSum -= dq.front().second;
                dq.pop_front();
            }
            if (weightSum + truck_weights[i] <= weight) {
                break;
            }
            answer++;
        }

        dq.push_back({answer, truck_weights[i]});
        weightSum += truck_weights[i];
        answer++;
    }
    
    while (!dq.empty()) {
        answer = dq.front().first + bridge_length;
        dq.pop_front();
    }
    return answer;
}
