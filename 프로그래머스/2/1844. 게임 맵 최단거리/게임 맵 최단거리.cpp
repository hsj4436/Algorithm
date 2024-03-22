#include<vector>
#include <queue>
using namespace std;

int N, M;
bool visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    N = maps.size();
    M = maps[0].size();
    queue<pair<int, pair<int, int>>> q;
    q.push({1, {0, 0}});
    visited[0][0] = true;
    
    while (!q.empty()) {
        int passed = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        if (x == N - 1 && y == M - 1) {
            answer = passed;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
                continue;
            }
            if (visited[nx][ny] || maps[nx][ny] == 0) {
                continue;
            }
            
            visited[nx][ny] = true;
            q.push({passed + 1, {nx, ny}});
        }
    }
    
    return answer;
}