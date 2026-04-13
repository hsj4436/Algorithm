import java.io.*;
import java.util.*;

public class Main {

    static final int INF = 1000 * 1000 + 1;

    static int N;
    static int[][] costs;
    static int[][][] dp; // N번째 집을 {R,G,B}로 칠할때, 1번집이 {R,G,B}인 경우 비용의 최솟값

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        costs = new int[N][3];
        dp = new int[N][3][3];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int j = 0; j < 3; j++) {
                costs[i][j] = Integer.parseInt(st.nextToken());
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = INF;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            dp[0][i][i] = costs[0][i];
        }

        for (int i = 1; i < N; i++) {
            for (int color = 0; color < 3; color++) {
                for (int j = 0; j < 3; j++) {
                    if (i == N - 1 && color == j) {
                        continue;
                    }
                    if (color == 0) {
                        dp[i][color][j] = Math.min(dp[i - 1][1][j], dp[i - 1][2][j]) + costs[i][color];
                    } else if (color == 1) {
                        dp[i][color][j] = Math.min(dp[i - 1][0][j], dp[i - 1][2][j]) + costs[i][color];
                    } else {
                        dp[i][color][j] = Math.min(dp[i - 1][0][j], dp[i - 1][1][j]) + costs[i][color];
                    }
                }
            }
        }

        int answer = INF;
        for (int color = 0; color < 3; color++) {
            for (int i = 0; i < 3; i++) {
                answer = Math.min(answer, dp[N - 1][color][i]);
            }
        }

        System.out.println(answer);
    }
}