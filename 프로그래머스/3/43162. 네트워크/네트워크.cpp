#include <string>
#include <vector>

using namespace std;

bool visited[201];
vector<int> graph[201];

void dfs(int cur) {
    for (int next : graph[cur]) {
        if (visited[next]) {
            continue;
        }
        visited[next] = true;
        dfs(next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[i].size(); j++) {
            if (computers[i][j] == 1 && i != j) {
                graph[i].push_back(j);
            }
        }
    }
    
    for (int i = 0; i < computers.size(); i++) {
        if (!visited[i]) {
            answer++;
            visited[i] = true;
            dfs(i);
        }
    }
    
    return answer;
}