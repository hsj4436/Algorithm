class Solution {
    
    private static int[][] INFO;
    private static int N;
    private static int M;
    
    private static int[][][] dp = new int[41][121][121];
    
    public int solution(int[][] info, int n, int m) {
        int answer = 0;
        
        INFO = info;
        N = n;
        M = m;
                
        for (int i = 0; i < 41; i++) {
            for (int j = 0; j < 121; j++) {
                for (int k = 0; k < 121; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        
        if (INFO[0][0] < N) {
            if (INFO.length > 1) {
                dp[0][0][0] = Math.max(dp[0][0][0], sol(1, INFO[0][0], 0, true));
                dp[0][0][0] = Math.max(dp[0][0][0], sol(1, INFO[0][0], 0, false));
            } else {
                dp[0][INFO[0][0]][0] = 1;
            }
        }
        if (INFO[0][1] < M) {
            if (INFO.length > 1) {
                dp[0][0][0] = Math.max(dp[0][0][0], sol(1, 0, INFO[0][1], true));
                dp[0][0][0] = Math.max(dp[0][0][0], sol(1, 0, INFO[0][1], false));
            } else {
                dp[0][0][INFO[0][1]] = 1;
            }
        }
        
        for (int i = 0 ; i < 121; i++) {
            for (int j = 0; j < 121; j++) {
                if (dp[INFO.length - 1][i][j] > 0) {
                    return i;
                }
            }
        }
        
        return -1;
    }
    
    private static int sol(int index, int A, int B, boolean isA) {
        if (index == INFO.length - 1) {
            if (isA) {
                if (A + INFO[index][0] < N) {
                    return dp[index][A + INFO[index][0]][B] = 1;
                } else {
                    return dp[index][A + INFO[index][0]][B] = 0;
                }
            } else {
                if (B + INFO[index][1] < M) {
                    return dp[index][A][B + INFO[index][1]] = 1;
                } else {
                    return dp[index][A][B + INFO[index][1]] = 0;
                }
            }
        }
        
        if (dp[index][A][B] != -1) {
            return dp[index][A][B];
        }

        dp[index][A][B] = 0;
        if (A + INFO[index][0] < N) {
            dp[index][A][B] = Math.max(dp[index][A][B], sol(index + 1, A + INFO[index][0], B, true));
            dp[index][A][B] = Math.max(dp[index][A][B], sol(index + 1, A + INFO[index][0], B, false));
        }
        
        if (B + INFO[index][1] < M) {
            dp[index][A][B] = Math.max(dp[index][A][B], sol(index + 1, A, B + INFO[index][1], true));
            dp[index][A][B] = Math.max(dp[index][A][B], sol(index + 1, A, B + INFO[index][1], false));
        }
        
        return dp[index][A][B];
    }
}