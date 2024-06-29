import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static final int[] dx = {-1, 0, 1, 0};
    static final int[] dy = {0, -1, 0, 1};

    static int N, M;
    static int[][] before;
    static int[][] after;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stk = new StringTokenizer(br.readLine());
        N = Integer.parseInt(stk.nextToken());
        M = Integer.parseInt(stk.nextToken());
        before = new int[N][M];
        for (int i = 0; i < N; i++) {
            stk = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                before[i][j] = Integer.parseInt(stk.nextToken());
            }
        }

        after = new int[N][M];
        for (int i = 0; i < N; i++) {
            stk = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                after[i][j] = Integer.parseInt(stk.nextToken());
            }
        }

        boolean[][] visitedA = new boolean[N][M];
        boolean[][] visitedB = new boolean[N][M];
        Queue<int[]> qA = new LinkedList<>();
        Queue<int[]> qB = new LinkedList<>();
        boolean isTransformed = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visitedA[i][j]) {
                    continue;
                }
                if (before[i][j] == after[i][j]) {
                    continue;
                }
                if (isTransformed) {
                    System.out.println("NO");
                    return;
                } else {
                    int aCount = 0;
                    qA.add(new int[]{i, j});
                    while (!qA.isEmpty()) {
                        int x = qA.peek()[0];
                        int y = qA.peek()[1];
                        qA.poll();
                        aCount++;
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
                                continue;
                            }
                            if (visitedA[nx][ny] || before[x][y] != before[nx][ny]) {
                                continue;
                            }
                            visitedA[nx][ny] = true;
                            qA.offer(new int[]{nx, ny});
                        }
                    }
                    int bCount = 0;
                    qB.add(new int[]{i, j});
                    while (!qB.isEmpty()) {
                        int x = qB.peek()[0];
                        int y = qB.peek()[1];
                        qB.poll();
                        bCount++;
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
                                continue;
                            }
                            if (visitedB[nx][ny] || after[x][y] != after[nx][ny] || before[nx][ny] == after[nx][ny]) {
                                continue;
                            }
                            visitedB[nx][ny] = true;
                            qB.offer(new int[]{nx, ny});
                        }
                    }
                    if (aCount != bCount) {
                        System.out.println("NO");
                        return;
                    }
                    isTransformed = true;
                }
            }
        }

        System.out.println("YES");
    }
}