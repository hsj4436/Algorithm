import java.io.*;
import java.util.*;

public class Solution {

    static int TC;
    static int N, L;
    static int[] T, K;
    static int[][] DP;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        TC = Integer.parseInt(br.readLine());

        for (int i = 1; i < TC + 1; i++) {
            System.out.println("#" + i + " " + solve(br));
        }
    }

    static int solve(BufferedReader br) throws Exception {
        StringTokenizer stk = new StringTokenizer(br.readLine());
        N = Integer.parseInt(stk.nextToken());
        L = Integer.parseInt(stk.nextToken());

        T = new int[N];
        K = new int[N];
        DP = new int[N + 1][L + 1];
        for (int i = 0; i < N; i++) {
            stk = new StringTokenizer(br.readLine());
            T[i] = Integer.parseInt(stk.nextToken());
            K[i] = Integer.parseInt(stk.nextToken());
        }

        for (int i = 1; i < N + 1; i++) {
            int score = T[i - 1];
            int calorie = K[i - 1];
            for (int j = 0; j < L + 1; j++) {
                if (j < calorie) {
                    DP[i][j] = DP[i - 1][j];
                } else {
                    DP[i][j] = Math.max(DP[i - 1][j], DP[i - 1][j - calorie] + score);
                }
            }
        }

        return DP[N][L];
    }

}