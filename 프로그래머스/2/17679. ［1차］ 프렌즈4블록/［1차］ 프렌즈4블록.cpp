#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int dx[3] = {0, -1, -1};
int dy[3] = {1, 0, 1};
char grid[31][31];

bool checkBlockFromHere(int x, int y) {
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > M - 1 || ny < 0 || ny > N - 1) {
            return false;
        }
        if (grid[nx][ny] != grid[x][y]) {
            return false;
        }
    }
    return true;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    N = n, M = m;
    
    for (int i = m - 1; i > -1; i--) {
        for (int j = 0; j < n; j++) {
            grid[m - 1 - i][j] = board[i][j];
        }
    }
    
    while (true) {
        int erased = 0;
        vector<pair<int, int>> v;
        for (int i = m - 1; i > -1; i--) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '#' && checkBlockFromHere(i, j)) {
                    v.push_back({i, j});
                    for (int k = 0; k < 3; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        v.push_back({nx, ny});
                    }
                }
            }
        }
        
        for (auto p : v) {
            if (grid[p.first][p.second] != '#') {
                erased++;
            }
            grid[p.first][p.second] = '#';
        }
        
        if (erased != 0) {
            answer += erased;
        } else {
            break;
        }
        for (int i = 0; i < n; i++) {
            int streak = 0;
            for (int j = 0; j < m; j++) {
                if (grid[j][i] == '#') {
                    streak++;
                    continue;
                }
                if (streak > 0) {
                    grid[j - streak][i] = grid[j][i];
                    grid[j][i] = '#';
                }
            }
        }
    }
    
    return answer;
}