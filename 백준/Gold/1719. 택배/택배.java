import java.io.*;
import java.util.*;

public class Main {
    
    private static int N = 0;
    private static int M = 0;
    private static int[][] dist = new int[201][201];
    private static int[][] answer = new int[201][201];
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        N = Integer.parseInt(stk.nextToken());
        M = Integer.parseInt(stk.nextToken());
        
        for (int i = 0; i < N + 1; i++) {
            Arrays.fill(dist[i], 987654321);
        }
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                answer[i][j] = j;
            }
        }
        
        int from = 0, to = 0, distance = 0;
        for (int i = 0; i < M; i++) {
            stk = new StringTokenizer(br.readLine());
            from = Integer.parseInt(stk.nextToken());
            to = Integer.parseInt(stk.nextToken());
            distance = Integer.parseInt(stk.nextToken());
            dist[from][to] = distance;
            answer[from][to] = to;
            dist[to][from] = distance;
            answer[to][from] = from;
        }
        
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                if (i == k) {
                    continue;
                }
                for (int j = 1; j <= N; j++) {
                    if (i == j || j == k) {
                        continue;
                    }
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        int initial = k;
                        while (initial != answer[i][initial]) {
                            initial = answer[i][initial];
                        }
                        answer[i][j] = initial;
                    }
                }
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) {
                    sb.append("- ");
                } else {
                    sb.append(answer[i][j] + " ");
                }
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}