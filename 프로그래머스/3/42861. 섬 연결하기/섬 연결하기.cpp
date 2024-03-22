#include <string>
#include <vector>
#include <queue>

using namespace std;

int parent[101];

int findParent(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = findParent(parent[x]);
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    int count = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    for (vector<int> v : costs) {
        pq.push({-v[2], {v[0], v[1]}});
    }
    while (count != n - 1) {
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        
        int px = findParent(x);
        int py = findParent(y);
        
        if (px == py) {
            continue;
        }
        
        answer += cost;
        if (parent[px] < parent[py]) {
            parent[py] = px;
        } else {
            parent[px] = py;
        }
        count++;
    }
    return answer;
}