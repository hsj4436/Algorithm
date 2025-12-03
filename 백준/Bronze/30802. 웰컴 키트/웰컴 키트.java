import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[] sizes = new int[6];
    static int T, P;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        StringTokenizer stk = new StringTokenizer(br.readLine());
        int i = 0;
        while (stk.hasMoreTokens()) {
            sizes[i] = Integer.parseInt(stk.nextToken());
            i++;
        }

        stk = new StringTokenizer(br.readLine());
        T = Integer.parseInt(stk.nextToken());
        P = Integer.parseInt(stk.nextToken());

        int shirts = 0;
        for (i = 0; i < 6; i++) {
            if (sizes[i] % T == 0) {
                shirts += sizes[i] / T;
            } else {
                shirts += (sizes[i] / T) + 1;
            }
        }

        System.out.println(shirts);
        System.out.println((N / P) + " " + (N % P));
    }
}