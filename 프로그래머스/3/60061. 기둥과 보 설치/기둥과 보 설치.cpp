#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool frame[102][102][2];

bool canInstallPillar(int x, int y);
bool canRemovePillar(int x, int y);
bool canInstallBeam(int x, int y);
bool canRemoveBeam(int x, int y);

bool canInstallPillar(int x, int y) {
    if ((x == 0) || (x > 0 && frame[x - 1][y][0]) || frame[x][y][1] || (y > 0 && frame[x][y - 1][1])) {
        return true;
    }
    return false;
}

bool canRemovePillar(int x, int y) {
    if (x + 1 <= N && frame[x + 1][y][0]) {
        if (!canInstallPillar(x + 1, y)) {
            return false;
        }
    }
    if (x + 1 <= N && frame[x + 1][y][1]) {
        if (!canInstallBeam(x + 1, y)) {
            return false;
        }
    }
    if (x + 1 <= N && y - 1 >= 0 && frame[x + 1][y - 1][1]) {
        if (!canInstallBeam(x + 1, y - 1)) {
            return false;
        }
    }
    if (y - 1 >= 0 && frame[x][y - 1][1]) {
        if (!canInstallBeam(x, y - 1)) {
            return false;
        }
    }
    if (frame[x][y][1]) {
        if (!canInstallBeam(x, y)) {
            return false;
        }
    }
    return true;
}

bool canInstallBeam(int x, int y) {
    if ((x - 1 >= 0 && frame[x - 1][y][0]) || (x - 1 >= 0 && y + 1 <= N && frame[x - 1][y + 1][0]) || 
        ((y - 1 >= 0 && frame[x][y - 1][1]) && (y + 1 <= N && frame[x][y + 1][1]))) {
        return true;
    }
    return false;
}

bool canRemoveBeam(int x, int y) {
    if (y - 1 >= 0 && frame[x][y - 1][1]) {
        if (!canInstallBeam(x, y - 1)) {
            return false;
        }
    }
    if (y + 1 <= N && frame[x][y + 1][1]) {
        if (!canInstallBeam(x, y + 1)) {
            return false;
        }
    }
    if (frame[x][y][0]) {
        if (!canInstallPillar(x, y)) {
            return false;
        }
    }
    if (y + 1 <= N && frame[x][y + 1][0]) {
        if (!canInstallPillar(x, y + 1)) {
            return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    for (vector<int> bf : build_frame) {
        if (bf[3] == 1) {
            // install
            if (bf[2] == 0) {
                // pillar   
                if (canInstallPillar(bf[1], bf[0])) {
                    frame[bf[1]][bf[0]][0] = true;
                }
            } else {
                // beam
                if (canInstallBeam(bf[1], bf[0])) {
                    frame[bf[1]][bf[0]][1] = true;
                }
            }
        } else {
            // remove
            if (bf[2] == 0) {
                // pillar
                frame[bf[1]][bf[0]][0] = false;
                if (!canRemovePillar(bf[1], bf[0])) {
                    frame[bf[1]][bf[0]][0] = true;
                }
            } else {
                // beam
                frame[bf[1]][bf[0]][1] = false;
                if (!canRemoveBeam(bf[1], bf[0])) {
                    frame[bf[1]][bf[0]][1] = true;
                }
            }
        }
    }
    
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (frame[i][j][0]) {
                vector<int> v;
                v.push_back(j);
                v.push_back(i);
                v.push_back(0);
                answer.push_back(v);
            }
            if (frame[i][j][1]) {
                vector<int> v;
                v.push_back(j);
                v.push_back(i);
                v.push_back(1);
                answer.push_back(v);
            }
        }
    }

    sort(answer.begin(), answer.end(), [&](vector<int> a, vector<int> b) {
       if (a[0] == b[0]) {
           if (a[1] == b[1]) {
               return a[2] < b[2];
           } else {
               return a[1] < b[1];
           }
       } else {
           return a[0] < b[0];
       }
    });
    
    return answer;
}