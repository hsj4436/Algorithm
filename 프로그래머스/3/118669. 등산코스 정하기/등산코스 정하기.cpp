#include <string>
#include <vector>

using namespace std;

int type[50001]; // 0 - rest, 1 - gate, 2 - summit
vector<pair<int, int>> path[50001];
int visited[50001];
int answerSummit = 50001;
int minIntensity = 10000001;

void dfs(int from, int cur, int maxIntensity) {
    if (type[cur] == 2) {
        if (maxIntensity < minIntensity) {
            minIntensity = maxIntensity;
            answerSummit = cur;
        } else if (maxIntensity == minIntensity) {
            answerSummit = min(cur, answerSummit);
        }
        return;
    }
    
    if (maxIntensity > minIntensity) {
        return;
    }
    
    for (pair<int, int> p : path[cur]) {
        if (p.first == from) {
            continue;
        }
        if (max(maxIntensity, p.second) >= visited[p.first]) {
            continue;
        }
        if (type[p.first] == 1) {
            continue;
        }
        visited[p.first] = max(maxIntensity, p.second);
        dfs(cur, p.first, max(maxIntensity, p.second));
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    for (int gate : gates) {
        type[gate] = 1;
    }
    for (int summit : summits) {
        type[summit] = 2;
    }
    for (vector<int> p : paths) {
        path[p[0]].push_back({p[1], p[2]});
        path[p[1]].push_back({p[0], p[2]});
    }
    
    for (int gate : gates) {
        fill_n(&visited[0], 50001, 10000001);
        visited[gate] = 0;
        dfs(-1, gate, 0);
    }
    
    answer.push_back(answerSummit);
    answer.push_back(minIntensity);
        
    return answer;
}