#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int cards = 0;
vector<pair<int, int>> cardPositions[7];
bool flippedPair[7];
int answer = 987654321;
vector<vector<int>> b;

int findMinKeyDown(int fx, int fy, int tx, int ty) {
    int ret = 1000000;
    queue<pair<pair<int, int>, int>> q;
    int visited[4][4];
    fill_n(&visited[0][0], 4 * 4, 50);
    visited[fx][fy] = 0;
    q.push({{fx, fy}, 0});
    
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int keyDown = q.front().second;
        q.pop();
        
        if (keyDown >= ret) {
            continue;
        }
        if (x == tx && y == ty) {
            ret = min(ret, keyDown);
            continue;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx > 3 || ny < 0 || ny > 3) {
                continue;
            }
            
            if (keyDown + 1 < visited[nx][ny]) {
                visited[nx][ny] = keyDown + 1;
                q.push({{nx, ny}, keyDown + 1});
            }

            if (b[nx][ny] != 0) {
                continue;
            }
            for (int j = 0; j < 3; j++) {
                int nnx = nx + dx[i];
                int nny = ny + dy[i];
                if (nnx < 0 || nnx > 3 || nny < 0 || nny > 3) {
                    if (keyDown + 1 < visited[nx][ny]) {
                        visited[nx][ny] = keyDown + 1;
                        q.push({{nx, ny}, keyDown + 1});
                    }
                    break;
                }
                if (b[nnx][nny] != 0) {
                    if (keyDown + 1 < visited[nnx][nny]) {
                        visited[nnx][nny] = keyDown + 1;
                        q.push({{nnx, nny}, keyDown + 1});
                    }
                    break;
                }
                nx = nnx, ny = nny;
            }
        }
    }
    return ret;
}

void backTrack(int x, int y, int target, int flipped, int keyDown) {
    if (keyDown >= answer) {
        return;
    }
    
    pair<int, int> t1 = cardPositions[target][0], t2 = cardPositions[target][1];
    
    int t1t2 = findMinKeyDown(x, y, t1.first, t1.second) + findMinKeyDown(t1.first, t1.second, t2.first, t2.second) + 2;
    int t2t1 = findMinKeyDown(x, y, t2.first, t2.second) + findMinKeyDown(t2.first, t2.second, t1.first, t1.second) + 2;
    
    b[t1.first][t1.second] = 0;
    b[t2.first][t2.second] = 0;
    flippedPair[target] = true;
    
    for (int i = 1; i <= 6; i++) {
        if (cardPositions[i].empty()) {
            continue;
        }
        if (flippedPair[i]) {
            continue;
        }   
        backTrack(t1.first, t1.second, i, flipped + 2, keyDown + t2t1);
        backTrack(t2.first, t2.second, i, flipped + 2, keyDown + t1t2); 
    }
    b[t1.first][t1.second] = target;
    b[t2.first][t2.second] = target;
    flippedPair[target] = false;
    
    if (flipped + 2 == cards) {
        answer = min(answer, keyDown + t1t2);
        answer = min(answer, keyDown + t2t1);
        return;
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) {
                cards++;
                cardPositions[board[i][j]].push_back({i, j});
            }
        }
    }
    b = board;
    for (int i = 1; i <= 6; i++) {
        if (cardPositions[i].empty()) {
            continue;
        }
        backTrack(r, c, i, 0, 0);
    }
    return answer;
}