import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, K;
    static long[] startOfPointSum;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stk = new StringTokenizer(br.readLine());
        N = Integer.parseInt(stk.nextToken());
        K = Integer.parseInt(stk.nextToken());

        long pointSum = 1;
        long numsInLine = 1;
        startOfPointSum = new long[2 * N + 1];
        for (int i = 2; i < 2 * N + 1; i++) {
            startOfPointSum[i] = pointSum;
            pointSum += numsInLine;
            if (i > N) {
                numsInLine--;
            } else {
                numsInLine++;
            }
        }

        String jumps = br.readLine();
        int x = 1, y = 1;
        long answer = 1;
        for (char ch : jumps.toCharArray()) {
            if (ch == 'U') {
                x--;
            } else if (ch == 'D') {
                x++;
            } else if (ch == 'L') {
                y--;
            } else {
                y++;
            }
            int sumOfPoint = x + y;
            if (sumOfPoint % 2 == 0) {
                if (sumOfPoint > N + 1) {
                    answer += startOfPointSum[sumOfPoint] + (y - (sumOfPoint - N));
                } else {
                    answer += startOfPointSum[sumOfPoint] + (sumOfPoint - 1 - x);
                }
            } else {
                if (sumOfPoint > N + 1) {
                    answer += startOfPointSum[sumOfPoint] + (x - (sumOfPoint - N));
                } else {
                    answer += startOfPointSum[sumOfPoint] + (sumOfPoint - 1 - y);
                }
            }
        }

        System.out.println(answer);
    }
}