#include <string>
#include <vector>

using namespace std;

int M, N;
vector<vector<int>> keys[4];

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    M = key.size();
    N = lock.size();
    keys[0] = key;
    
    for (int i = 1; i < 4; i++) {
        keys[i] = vector<vector<int>>(M);
        for (int j = 0; j < M; j++) {
            keys[i][j] = vector<int>(M);
        }
    }
    
    for (int i = 1; i < 4; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                keys[i][k][M - 1 - j] = keys[i - 1][j][k];
            }
        }
    }
    
    int toFill = 0;
    int newLock[2 * M + N][2 * M + N];
    for (int i = 0; i < 2 * M + N; i++) {
        for (int j = 0; j < 2 * M + N; j++) {
            newLock[i][j] = 2;
        }
    }
    for (int i = M; i < M + N; i++) {
        for (int j = M; j < M + N; j++) {
            newLock[i][j] = lock[i - M][j - M];
            if (lock[i - M][j - M] == 0) {
                toFill++;
            }
        }
    }
    
    for (int x = 0; x < M + N; x++) {
        for (int y = 0; y < M + N; y++) {
            for (int i = 0; i < 4; i++) {
                bool isCollide = false;
                int filled = 0;
                for (int j = 0; j < M; j++) {
                    for (int k = 0; k < M; k++) {
                        if ((newLock[x + j][y + k] == 1 && keys[i][j][k] == 1) || (newLock[x + j][y + k] == 0 && keys[i][j][k] == 0)) {
                            isCollide = true;
                            break;
                        }
                        if (newLock[x + j][y + k] == 0 && keys[i][j][k] == 1) {
                            filled++;
                        }
                    }
                    if (isCollide) {
                        break;
                    }
                    if (filled == toFill) {
                        return true;
                    }
                }
            }
        }
    }

    
    return answer;
}