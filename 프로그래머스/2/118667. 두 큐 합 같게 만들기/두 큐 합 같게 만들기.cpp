#include <string>
#include <vector>
#include <queue>

#define LL long long

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    LL half = 0;
    LL q1Sum = 0, q2Sum = 0;
    queue<LL> q1, q2;
    for (int i : queue1) {
        q1Sum += i;
        q1.push(i);
    }
    for (int i : queue2) {
        q2Sum += i;
        q2.push(i);
    }
    half = (q1Sum + q2Sum) / 2;
    
    while (q1Sum != half && q2Sum != half) {
        if (answer > (queue1.size() + queue2.size()) * 4) {
            answer = -1;
            break;
        }
        if (q1Sum > q2Sum) {
            LL front = q1.front();
            q1.pop();
            q1Sum -= front;
            q2.push(front);
            q2Sum += front;
        } else if (q1Sum < q2Sum) {
            LL front = q2.front();
            q2.pop();
            q2Sum -= front;
            q1.push(front);
            q1Sum += front;
        }
        answer++;
    }
    
    return answer;
}