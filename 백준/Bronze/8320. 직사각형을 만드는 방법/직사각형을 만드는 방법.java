import java.io.*;
import java.util.*;

public class Main {

    static int N;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        int answer = N;
        for (int i = 2; i < N + 1; i++) {
            int minColumn = 0;
            for (int j = i - 1; j > 0; j--) {
                if (j * i <= N) {
                    minColumn = j + 1;
                    break;
                }
            }
            if (i * minColumn <= N && (N / i) - minColumn + 1 > 0) {
                answer += (N / i) - minColumn + 1;
            }
        }

        System.out.println(answer);
    }
}