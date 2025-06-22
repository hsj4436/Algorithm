import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static final int MOD = 10007;
    private static int N;
    private static int[][] combinations = new int[53][53];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());

        N = Integer.parseInt(stk.nextToken());

        combinations[0][0] = 1;
        combinations[1][0] = 1;
        combinations[1][1] = 1;

        for (int i = 2; i < 53; i++) {
            combinations[i][0] = 1;
            combinations[i][i] = 1;
            for (int j = 1; j < 53; j++) {
                combinations[i][j] = (combinations[i - 1][j - 1] + combinations[i - 1][j]) % MOD;
            }
        }

        int answer = 0;
        for (int i = 4; i <= N; i += 4) {
            if ((i / 4) % 2 == 1) {
                answer = (answer + combinations[13][i / 4] * combinations[52 - i][N - i]) % MOD;
            } else {
                answer = (answer - combinations[13][i / 4] * combinations[52 - i][N - i]) % MOD;
            }

            if (answer < 0) {
                answer += MOD;
                answer %= MOD;
            }
        }

        System.out.println(answer % MOD);
    }
}