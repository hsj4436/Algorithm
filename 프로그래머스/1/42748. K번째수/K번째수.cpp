#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> v : commands) {
        int i = v[0] - 1, j = v[1] - 1, k = v[2];
        priority_queue<int, vector<int>, greater<int>> pq;
        for (; i < j + 1; i++) {
            pq.push(array[i]);
        }
        int count = 0;
        while (count != k - 1) {
            pq.pop();
            count++;
        }
        answer.push_back(pq.top());
    }
    return answer;
}