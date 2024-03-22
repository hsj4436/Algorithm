#include <string>
#include <vector>

using namespace std;

int N;
int dp[1000001][2]; // 0 - don't steal 0th home, 1 - steal 0th home

int solution(vector<int> money) {
    int answer = 0;
    N = money.size();
    
    dp[0][0] = 0;
    dp[0][1] = money[0];
    dp[1][0] = money[1];
    dp[1][1] = max(money[0], money[1]);
    for (int i = 2; i < N; i++) {
        dp[i][0] = max(dp[i - 2][0] + money[i], dp[i - 1][0]);
        if (i == N - 1) {
            dp[i][1] = max(dp[i - 2][1], max(dp[i - 1][1], dp[i - 1][0]));
        } else {
            dp[i][1] = max(dp[i - 2][1] + money[i], dp[i - 1][1]);
        }
    }

    answer = max(dp[N - 1][0], dp[N - 1][1]);
    return answer;
}