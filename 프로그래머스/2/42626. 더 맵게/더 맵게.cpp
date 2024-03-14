#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i : scoville) {
        sum += i;
        pq.push(i);
    }
    
    while (!pq.empty()) {
        if (pq.top() >= K) {
            break;
        }
        answer++;
        int s1 = pq.top();
        pq.pop();
        if (pq.empty()) {
            break;
        }
        int s2 = pq.top();
        pq.pop();
        pq.push(s1 + s2 * 2);
    }
    
    if (pq.empty()) {
        answer = -1;
    }
    
    return answer;
}