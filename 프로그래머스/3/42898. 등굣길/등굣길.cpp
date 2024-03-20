#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int M, N;
int dp[101][101];

int dfs(int x, int y) {
    if (dp[x][y] != 0) {
        return dp[x][y];
    }
    
    int nx = x + 1;
    int ny = y;
    if (nx <= M && dp[nx][ny] != -1) {
        dp[x][y] += dfs(nx, ny);
        dp[x][y] %= MOD;
    }
    nx = x;
    ny = y + 1;
    if (ny <= N && dp[nx][ny] != -1) {
        dp[x][y] += dfs(nx, ny);
        dp[x][y] %= MOD;
    }
    
    return dp[x][y];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    M = m;
    N = n;
    for (vector<int> v : puddles) {
        dp[v[0]][v[1]] = -1;
    }
    dp[m][n] = 1;
    
    answer = dfs(1, 1);
    
    return answer;
}