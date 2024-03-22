#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<bool>> visited;
map<string, int> limits;
map<string, vector<string>> graph;
vector<string> answer;

bool dfs(string current) {
    bool isEnd = true;
    for (auto p : limits) {
        if (p.second != 0) {
            isEnd = false;
        }
    }
    if (isEnd) {
        return true;
    }
    for (int i = 0; i < graph[current].size(); i++) {
        if (visited[current][i] || limits[graph[current][i]] == 0) {
            continue;
        }
        visited[current][i] = true;
        limits[graph[current][i]]--;
        if (dfs(graph[current][i])) {
            answer.push_back(graph[current][i]);
            return true;
        }
        limits[graph[current][i]]++;
        visited[current][i] = false;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    for (vector<string> v : tickets) {
        graph[v[0]].push_back(v[1]);
        limits[v[1]]++;
    }
    for (auto it = graph.begin(); it != graph.end(); it++) {
        sort(it->second.begin(), it->second.end());
        visited[it->first].resize(it->second.size());
    }

    dfs("ICN");
    answer.push_back("ICN");

    reverse(answer.begin(), answer.end());

    return answer;
}