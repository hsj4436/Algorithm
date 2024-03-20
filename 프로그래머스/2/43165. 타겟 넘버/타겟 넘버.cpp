#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    q.push({0, -numbers[0]});
    q.push({0, numbers[0]});
    
    while (!q.empty()) {
        int index = q.front().first;
        int sum = q.front().second;
        q.pop();
        
        if (index == numbers.size() - 1) {
            if (sum == target) {
                answer++;
            }
            continue;
        }
        
        q.push({index + 1, sum + numbers[index + 1]});
        q.push({index + 1, sum - numbers[index + 1]});
    }
    
    return answer;
}