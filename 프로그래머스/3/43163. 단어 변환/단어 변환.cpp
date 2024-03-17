#include <string>
#include <vector>
#include <queue>
#include <map>

#define INF 987654321

using namespace std;

map<string, int> visited;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool possible = false;
    for (string word : words) {
        visited[word] = INF;
        if (word == target) {
            possible = true;
        }
    }
    if (!possible) {
        return 0;
    }
    
    visited[begin] = 0;
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    while (!q.empty()) {
        string cur = q.front().first;
        int count = q.front().second;
        q.pop();
        
        for (string word : words) {
            int differenceCount = 0;
            for (int i = 0; i < word.size(); i++) {
                if (cur[i] != word[i]) {
                    differenceCount++;
                }
            }
            if (differenceCount == 1 && count + 1 < visited[word]) {
                visited[word] = count + 1;
                q.push({word, count + 1});
            }
        }
    }
    answer = visited[target];
    
    return answer;
}