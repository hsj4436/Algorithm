import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int[][] ground;
    static int[][] sum;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stk = new StringTokenizer(br.readLine());
        M = Integer.parseInt(stk.nextToken());
        N = Integer.parseInt(stk.nextToken());
        ground = new int[M + 1][N + 1];
        sum = new int[M + 1][N + 1];

        for (int i = 1; i < M + 1; i++) {
            stk = new StringTokenizer(br.readLine());
            for (int j = 1; j < N + 1; j++) {
                ground[i][j] = Integer.parseInt(stk.nextToken());
            }
        }
        for (int i = 1; i < M + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                sum[i][j] = ground[i][j] + sum[i - 1][j];
            }
        }
        for (int i = 1; i < M + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                sum[i][j] += sum[i][j - 1];
            }
        }

        int answer = 0;
        for (int i = 1; i < M + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                int maxLength = Math.min(i, j);
                for (int k = maxLength; k > 0; k--) {
                    if (k < answer) {
                        break;
                    }
                    int groundSum = sum[i][j] - sum[i][j - k] - sum[i - k][j] + sum[i - k][j - k];
                    if (groundSum == 0 && k > answer) {
                        answer = k;
                        break;
                    }
                }
            }
        }
        System.out.println(answer);
    }
}