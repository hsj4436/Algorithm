import java.io.*;
import java.util.*;

public class Main {
    
    private static final int MILK = 3;
    
    private static int N = 0;
    private static int[][] city = new int[1001][1001];
    private static int[][][] dp = new int[1001][1001][2]; // {milk count, last milk kind}
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        
        StringTokenizer stk;
        for (int i = 1; i <= N; i++) {
            stk = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                city[i][j] = Integer.parseInt(stk.nextToken());
            }
        }
        
        if (city[1][1] == 0) {
            dp[1][1][0] = 1;
            dp[1][1][1] = 0;
        } else {
            dp[1][1][0] = 0;
            dp[1][1][1] = -1;
        }
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }
                if (i - 1 > 0 && dp[i - 1][j][0] >= dp[i][j][0]) {
                    dp[i][j][0] = dp[i - 1][j][0];
                    dp[i][j][1] = dp[i - 1][j][1];
                }
                if (j - 1 > 0 && dp[i][j - 1][0] >= dp[i][j][0]) {
                    dp[i][j][0] = dp[i][j - 1][0];
                    dp[i][j][1] = dp[i][j - 1][1];
                }
                if (i - 1 > 0 && (dp[i - 1][j][1] + 1) % MILK == city[i][j] && dp[i - 1][j][0] + 1 > dp[i][j][0]) {
                    dp[i][j][0] = dp[i - 1][j][0] + 1;
                    dp[i][j][1] = city[i][j];
                }
                if (j - 1 > 0 && (dp[i][j - 1][1] + 1) % MILK == city[i][j] && dp[i][j - 1][0] + 1 > dp[i][j][0]) {
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                    dp[i][j][1] = city[i][j];
                }
            }
        }
        System.out.println(dp[N][N][0]);
    }
}