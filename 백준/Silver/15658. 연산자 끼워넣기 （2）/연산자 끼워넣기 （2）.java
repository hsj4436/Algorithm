import java.io.*;
import java.util.*;

public class Main {
    
    private static int N = 0;
    private static int[] arr = new int[11];
    private static int[] op = new int[4];
    private static int maxAnswer = Integer.MIN_VALUE;
    private static int minAnswer = Integer.MAX_VALUE;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    
        N = Integer.parseInt(br.readLine());
        StringTokenizer stk = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(stk.nextToken());
        }
        stk = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) {
            op[i] = Integer.parseInt(stk.nextToken());
        }
        
        backTrack(arr[0], 1);
        
        System.out.println(maxAnswer);
        System.out.println(minAnswer);
    }
    
    static void backTrack(int current, int index) {
        if (index == N) {
            minAnswer = Math.min(minAnswer, current);
            maxAnswer = Math.max(maxAnswer, current);
            return;
        }
        
        if (op[0] > 0) {
            // +
            int next = current + arr[index];
            op[0]--;
            backTrack(next, index + 1);
            op[0]++;
        }
        if (op[1] > 0) {
            // -
            int next = current - arr[index];
            op[1]--;
            backTrack(next, index + 1);
            op[1]++;
        }
        if (op[2] > 0) {
            // *
            int next = current * arr[index];
            op[2]--;
            backTrack(next, index + 1);
            op[2]++;
        }
        if (op[3] > 0) {
            // /
            int next;
            if (current < 0 && arr[index] > 0) {
                next = ((current * -1) / arr[index]) * -1;
            } else {
                next = current / arr[index];
            }
            op[3]--;
            backTrack(next, index + 1);
            op[3]++;
        }
        
    }
}