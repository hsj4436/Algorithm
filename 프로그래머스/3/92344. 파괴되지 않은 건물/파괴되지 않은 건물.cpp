#include <string>
#include <vector>

using namespace std;

int N, M;
int height = 1;
int diff[1002][1002];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    N = board.size(), M = board[0].size();
    for (vector<int> s : skill) {
        int x1 = s[1], y1 = s[2], x2 = s[3], y2 = s[4], d = s[5];
        if (s[0] == 1) {
            d *= -1;
        }
        diff[x1][y1] += d;
        diff[x1][y2 + 1] += d * (-1);
        diff[x2 + 1][y1] += d * (-1);
        diff[x2 + 1][y2 + 1] += d;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j > 0) {
                diff[i][j] += diff[i][j - 1];
            }
            if (i > 0) {
                diff[i][j] += diff[i - 1][j];
            }
            if (i > 0 && j > 0) {
                diff[i][j] -= diff[i - 1][j - 1];
            }
            if (diff[i][j] + board[i][j] > 0) {
                answer++;
            }
        }
    }
    
    return answer;
}