import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[] lines;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        lines = new int[N + 1];

        StringTokenizer stk = new StringTokenizer(br.readLine());
        for (int i = 1; i < N + 1; i++) {
            lines[i] = Integer.parseInt(stk.nextToken());
        }

        List<Integer> LIS = new ArrayList<>();
        for (int i = 1; i < N + 1; i++) {
            if (LIS.isEmpty()) {
                LIS.add(lines[i]);
            } else if (LIS.get(LIS.size() - 1) < lines[i]) {
                LIS.add(lines[i]);
            } else {
                int index = 0;
                int left = 0, right = LIS.size() - 1;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (LIS.get(mid) < lines[i]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                index = right;
                LIS.set(index, lines[i]);
            }
        }

        System.out.println(N - LIS.size());
    }
}