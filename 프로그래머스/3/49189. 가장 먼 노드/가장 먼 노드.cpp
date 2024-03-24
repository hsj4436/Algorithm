#include <string>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

vector<int> edges[20001];
int distances[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (vector<int> v : edge) {
        edges[v[0]].push_back(v[1]);
        edges[v[1]].push_back(v[0]);
    }
    fill(distances + 1, distances + n + 1, INF);
    distances[1] = 0;
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        int d = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for (auto next : edges[cur]) {
            if (d + 1 < distances[next]) {
                distances[next] = d + 1;
                pq.push({-(d + 1), next});
            }
        }
    }
    
    int maxDistance = 0, maxNodes = 0;
    for (int i = 1; i < n + 1; i++) {
        if (distances[i] > maxDistance) {
            maxDistance = distances[i];
            maxNodes = 1;
        } else if (distances[i] == maxDistance) {
            maxNodes++;
        }
    }
    answer = maxNodes;
    return answer;
}