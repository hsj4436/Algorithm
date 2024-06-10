#include <string>
#include <vector>

using namespace std;

int N;
bool isWolf[17];
vector<int> edge[17];
pair<int, int> dp[17][1 << 17];
int answer = 1;
void sol(int state) {
    int wolves = 0, sheeps = 0;
    for (int i = 0; i < N; i++) {
        if (state & (1 << i)) {
            if (isWolf[i]) {
                wolves++;
            } else {
                sheeps++;
            }
        }
    }
    
    if (wolves >= sheeps) {
        return;
    }
    
    answer = max(answer, sheeps);
    
    for (int i = 0; i < N; i++) {
        if (!(state & (1 << i))) {
            continue;
        }
        for (int next : edge[i]) {
            if (state & (1 << next)) {
                continue;
            }
            sol(state | (1 << next));
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    N = info.size();
    for (int i = 0; i < info.size(); i++) {
        isWolf[i] = info[i];
    }
    for (vector<int> p : edges) {
        edge[p[0]].push_back(p[1]);
        edge[p[1]].push_back(p[0]);
    }
    sol(1);
    return answer;
}