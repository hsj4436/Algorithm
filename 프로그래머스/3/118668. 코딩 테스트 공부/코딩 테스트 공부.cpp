#include <string>
#include <vector>

using namespace std;

int maxAlp = 0, maxCop = 0;
int dp[151][151]; // {alp, cop}


int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    fill_n(&dp[0][0], 151 * 151, 10000000);
    
    for (vector<int> problem : problems) {
        maxAlp = max(maxAlp, problem[0]);
        maxCop = max(maxCop, problem[1]);
    }
    
    alp = min(alp, maxAlp);
    cop = min(cop, maxCop);
    dp[alp][cop] = 0;
    
    for (int i = alp; i < maxAlp + 1; i++) {
        for (int j = cop; j < maxCop + 1; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            for (vector<int> p : problems) {
                if (i < p[0] || j < p[1]) {
                    continue;
                }
                int nextAlp = min(maxAlp, i + p[2]);
                int nextCop = min(maxCop, j + p[3]);
                dp[nextAlp][nextCop] = min(dp[nextAlp][nextCop], dp[i][j] + p[4]);
            }
        }
    }
    answer = dp[maxAlp][maxCop];
    return answer;
}