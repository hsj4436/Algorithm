import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int[] height;
    static int[] orders;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stk = new StringTokenizer(br.readLine());
        N = Integer.parseInt(stk.nextToken());
        M = Integer.parseInt(stk.nextToken());

        height = new int[N + 2];
        stk = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            height[i] = Integer.parseInt(stk.nextToken());
        }

        orders = new int[N + 2];
        int A, B, K;
        for (int i = 0; i < M; i++) {
            stk = new StringTokenizer(br.readLine());
            A = Integer.parseInt(stk.nextToken());
            B = Integer.parseInt(stk.nextToken());
            K = Integer.parseInt(stk.nextToken());
            orders[A] += K;
            orders[B + 1] += -K;
        }

        int order = 0;
        for (int i = 1; i <= N; i++) {
            order += orders[i];
            height[i] += order;
            System.out.print(height[i] + " ");
        }
    }
}