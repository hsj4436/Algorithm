import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static List<List<Integer>> pair = new ArrayList<>();
    static boolean[] visited;
    static int[] assignedWorker;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stk = new StringTokenizer(br.readLine());
        N = Integer.parseInt(stk.nextToken());
        M = Integer.parseInt(stk.nextToken());

        assignedWorker = new int[M + 1];
        for (int i = 0; i < N + 1; i++) {
            pair.add(new ArrayList<>());
        }

        int works;
        for (int i = 1; i < N + 1; i++) {
            stk = new StringTokenizer(br.readLine());
            works = Integer.parseInt(stk.nextToken());
            for (int j = 0; j < works; j++) {
                pair.get(i).add(Integer.parseInt(stk.nextToken()));
            }
        }

        int answer = 0;
        for (int i = 1; i < N + 1; i++) {
            visited = new boolean[N + 1];
            if (dfs(i)) {
                answer++;
            }
        }

        System.out.println(answer);
    }

    static boolean dfs(int worker) {
        if (visited[worker]) {
            return false;
        }
        visited[worker] = true;

        for (int job : pair.get(worker)) {
            if (assignedWorker[job] == 0 || dfs(assignedWorker[job])) {
                assignedWorker[job] = worker;
                return true;
            }
        }

        return false;
    }
}