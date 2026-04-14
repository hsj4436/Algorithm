import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[][] board;
    static boolean[][] visited;

    static final int[] dx = new int[]{1, 0};
    static final int[] dy = new int[]{0, 1};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        board   = new int[N][N];
        visited = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(stk.nextToken());
            }
        }

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        visited[0][0] = true;
        while (!q.isEmpty()) {
            int[] cur = q.poll();

            for (int i = 0; i < 2; i++) {
                int nx = cur[0] + dx[i] * board[cur[0]][cur[1]];
                int ny = cur[1] + dy[i] * board[cur[0]][cur[1]];

                if (nx > N - 1 || ny > N - 1) {
                    continue;
                }

                if (board[nx][ny] == -1) {
                    System.out.println("HaruHaru");
                    return;
                }
                
                if (visited[nx][ny]) {
                    continue;
                }
                visited[nx][ny] = true;
                q.add(new int[]{nx, ny});
            }
        }

        System.out.println("Hing");
    }
}