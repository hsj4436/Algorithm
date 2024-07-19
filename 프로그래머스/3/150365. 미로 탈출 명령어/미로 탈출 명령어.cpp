#include <string>
#include <vector>

using namespace std;

char order[4] = {'d', 'l', 'r', 'u'};
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

int N, M;
int SX, SY, EX, EY;
int K;
bool possible[51][51][2501];

string answer;

bool backTrack(int x, int y, int moved, string trace) {
    if (x == EX && y == EY) {
        if (moved == K) {
            answer = trace;
            return true;
        }
        if ((K - moved) % 2 != 0) {
            possible[x][y][moved] = false;
            return false;
        }
    }
    
    if (moved == K) {
        possible[x][y][moved] = false;
        return false;
    }
    
    
    if (abs(x - EX) + abs(y - EY) > K - moved) {
        possible[x][y][moved] = false;
        return false;
    }
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > N || ny < 1 || ny > M) {
            continue;
        }
        if (!possible[nx][ny][moved + 1]) {
            continue;
        }
        trace.push_back(order[i]);
        if (backTrack(nx, ny, moved + 1, trace)) {
            return true;
        }
        possible[nx][ny][moved + 1] = false;
        trace.pop_back();
    }
    possible[x][y][moved] = false;
    return false;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    N = n, M = m;
    SX = x, SY = y, EX = r, EY = c;
    K = k;
    
    if (abs(x - r) + abs(y - c) > K) {
        answer = "impossible";
        return answer;
    }
    
    fill_n(&possible[0][0][0], 51 * 51 * 2501, true);
    
    if (!backTrack(SX, SY, 0, "")) {
        answer = "impossible";
    }
    
    return answer;
}