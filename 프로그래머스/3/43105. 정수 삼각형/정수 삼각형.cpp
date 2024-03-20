#include <string>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    dp.resize(triangle.size());
    for (int i = 0; i < triangle.size(); i++) {
        dp[i].resize(triangle[i].size());
    }
    
    dp[0][0] = triangle[0][0];
    for (int i = 0; i < triangle.size() - 1; i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
        }
    }
    
    for (int i = 0; i < dp[dp.size() - 1].size(); i++) {
        answer = max(answer, dp[dp.size() - 1][i]);
    }
    return answer;
}