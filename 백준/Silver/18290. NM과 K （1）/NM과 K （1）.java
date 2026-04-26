import java.io.*;
import java.util.*;

public class Main {

    static int N, M, K;
    static int[][] board;
    static boolean[] visited;
    static int answer;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stk = new StringTokenizer(br.readLine());

        N = Integer.parseInt(stk.nextToken());
        M = Integer.parseInt(stk.nextToken());
        K = Integer.parseInt(stk.nextToken());

        board = new int[N][M];
        visited = new boolean[N * M];
        answer = -10001 * K;
        for (int i = 0; i < N; i++) {
            stk = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(stk.nextToken());
            }
        }

        selectCell(0, 0, 0);

        System.out.println(answer);
    }

    private static void selectCell(int selected, int start, int sum) {
        for (int i = start; i < N * M; i++) {
            int x = i / M;
            int y = i % M;
            boolean possible = true;
            for (int j = 0; j < i; j++) {
                if (visited[j]) {
                    int px = j / M;
                    int py = j % M;
                    if ((y == py && Math.abs(px - x) == 1) || (x == px && Math.abs(py - y) == 1)) {
                        possible = false;
                        break;
                    }
                }
            }
            if (!possible) {
                continue;
            }
            visited[i] = true;
            if (selected + 1 == K) {
                answer = Math.max(answer, sum + board[x][y]);
            } else {
                selectCell(selected + 1, i + 1, sum + board[x][y]);
            }
            visited[i] = false;
        }
    }
}