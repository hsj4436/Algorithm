#include <string>
#include <vector>

#define INF 987654321

using namespace std;

int dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    fill(&dist[0][0], &dist[200][201], INF);
    for (vector<int> fare : fares) {
        dist[fare[0]][fare[1]] = fare[2];
        dist[fare[1]][fare[0]] = fare[2];
    }
    
    for (int i = 1; i < n + 1; i++) {
        dist[i][i] = 0;
    }
    
    for (int k = 1; k < n + 1; k++) {
        for (int i = 1; i < n + 1; i++) {
            if (i == k) {
                continue;
            }
            for (int j = 1; j < n + 1; j++) {
                if (i == j || j == k) {
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    answer = INF;
    for (int i = 1; i < n + 1; i++) {
        if (dist[s][i] == INF || dist[i][a] == INF || dist[i][b] == INF) {
            continue;
        }
        if (i == a) {
            answer = min(answer, dist[s][i] + dist[i][b]);
        } else if (i == b) {
            answer = min(answer, dist[s][i] + dist[i][a]);
        } else if (i == s) {
            answer = min(answer, dist[i][a] + dist[i][b]);            
        } else {
            answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
        }
    }
    
    return answer;
}