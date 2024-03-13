#include <string>
#include <vector>
#include <queue>

#define PII pair<int, int>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> jobQueue;
    for (int i = 0; i < priorities.size(); i++) {
        jobQueue.push(priorities[i]);
    }
    
    int index = 0;
    while (!jobQueue.empty()) {
        if (priorities[index] == jobQueue.top()) {
            answer++;
            jobQueue.pop();
            if (index == location) {
                break;
            }
        }
        index++;
        index %= priorities.size();
    }
    return answer;
}