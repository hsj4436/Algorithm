#include <string>
#include <vector>
#include <iostream>

#define INF 987654321

using namespace std;

int dist[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for (vector<int> v : results) {
        dist[v[0]][v[1]] = 1;
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
                if (dist[i][k] == 1 && dist[k][j] == 1) {
                    dist[i][j] = 1;
                }
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        int count = 0;
        for (int j = 1; j < n + 1; j++) {
            if (dist[i][j] == 1 || dist[j][i] == 1) {
                count++;
            }
        }
        if (count == n - 1) {
            answer++;
        }
    }
    
    return answer;
}