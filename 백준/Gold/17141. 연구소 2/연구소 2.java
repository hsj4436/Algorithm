import java.io.*;
import java.util.*;

public class Main {

    static int answer;
    static int N, M;
    static int[][] lab;

    static final int[] dx = new int[]{-1, 0, 1, 0};
    static final int[] dy = new int[]{0, -1, 0, 1};

    static boolean[][] visited;
    static List<int[]> virusPosition = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stk = new StringTokenizer(br.readLine());
        N = Integer.parseInt(stk.nextToken());
        M = Integer.parseInt(stk.nextToken());

        answer = N * N;
        lab = new int[N][N];
        for (int i = 0; i < N; i++) {
            stk = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                lab[i][j] = Integer.parseInt(stk.nextToken());
                if (lab[i][j] == 2) {
                    virusPosition.add(new int[]{i, j});
                }
            }
        }

        selectVirusPosition(0, new ArrayList<>());

        if (answer == N * N) {
            System.out.println(-1);
        } else {
            System.out.println(answer);
        }
    }

    private static void selectVirusPosition(int index, List<int[]> selectedPosition) {
        if (selectedPosition.size() == M) {
            checkTime(selectedPosition);
            return;
        }
        for (int i = index; i < virusPosition.size(); i++) {
            selectedPosition.add(new int[]{virusPosition.get(i)[0], virusPosition.get(i)[1]});
            selectVirusPosition(i + 1, selectedPosition);
            selectedPosition.remove(selectedPosition.size() - 1);
        }
    }

    private static void checkTime(List<int[]> selectedPosition) {
        visited = new boolean[N][N];
        Queue<int[]> q = new LinkedList<>();
        int time = 0;
        for (int[] position : selectedPosition) {
            visited[position[0]][position[1]] = true;
            q.add(new int[]{0, position[0], position[1]});
        }

        while (!q.isEmpty()) {
            int[] cur = q.poll();

            time = Math.max(time, cur[0]);
            if (time >= answer) {
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nx = cur[1] + dx[i];
                int ny = cur[2] + dy[i];

                if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
                    continue;
                }
                if (visited[nx][ny] || lab[nx][ny] == 1) {
                    continue;
                }
                visited[nx][ny] = true;
                q.add(new int[]{cur[0] + 1, nx, ny});
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((lab[i][j] == 0 || lab[i][j] == 2) && !visited[i][j]) {
                    return;
                }
            }
        }

        answer = Math.min(answer, time);
    }
}