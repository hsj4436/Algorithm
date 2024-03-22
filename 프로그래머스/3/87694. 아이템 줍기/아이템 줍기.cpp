#include <string>
#include <vector>
#include <queue>

#define INF 1000001

using namespace std;

int map[152][152];
bool visited[152][152];

int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[8] = {0, -1, 0, 1, 1, -1, 1, -1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    for (int i = 0; i < 152; i++) {
        for (int j = 0; j < 152; j++) {
            map[i][j] = INF;
        }
    }
    for (vector<int> v : rectangle) {
        for (int i = min(v[1], v[3]) * 3; i < max(v[1], v[3]) * 3 + 1; i++) {
            for (int j = min(v[0], v[2]) * 3; j < max(v[0], v[2]) * 3 + 1; j++) {
                map[i][j] = -1;
            }
        }  
    }
    
    queue<pair<int, int>> q;
    map[0][0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx > 151 || ny < 0 || ny > 151) {
                continue;
            }
            
            if (map[nx][ny] == -1) {
                map[nx][ny] = 1;
                continue;
            }
            
            if (map[nx][ny] == INF) {
                map[nx][ny] = 0;
                q.push({nx, ny});
            }
        }
    }

    queue<pair<int, pair<int, int>>> Q;
    visited[characterY * 3][characterX * 3] = true;
    Q.push({1, {characterY * 3, characterX * 3}});
    
    while (!Q.empty()) {
        int d = Q.front().first;
        int x = Q.front().second.first;
        int y = Q.front().second.second;
        Q.pop();
        
        if (x == itemY * 3 && y == itemX * 3) {
            answer = d;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx > 151 || ny < 0 || ny > 151) {
                continue;
            }
            
            if (visited[nx][ny] || map[nx][ny] == -1 || map[nx][ny] == 0) {
                continue;
            }
            
            visited[nx][ny] = true;
            Q.push({d + 1, {nx, ny}});
        }
    }
    answer /= 3;
    return answer;
}