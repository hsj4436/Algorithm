#include <string>
#include <vector>
#include <queue>
#include <iostream>
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
                cout << "t : " << answer << ", truck out: " << dq.front().second << "\n";
                dq.pop_front();
            }
            if (weightSum + truck_weights[i] <= weight) {
                break;
            }
            answer++;
        }
        // if (dq.size() == bridge_length || weightSum + truck_weights[i] > weight) {
        //     while (weightSum + truck_weights[i] > weight) {
        //         answer = dq.front().first + bridge_length;
        //         cout << "t : " << answer << ", truck out: " << dq.front().second << "\n";
        //         weightSum -= dq.front().second;
        //         dq.pop_front();
        //     }
        // }
        dq.push_back({answer, truck_weights[i]});
        cout << "t : " << answer << ", truck in: " << dq.back().second << "\n";
        weightSum += truck_weights[i];
        answer++;
    }
    
    while (!dq.empty()) {
        answer = dq.front().first + bridge_length;
        dq.pop_front();
    }
    return answer;
}