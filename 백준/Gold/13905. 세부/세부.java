import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int S, E;
    static List<List<Integer>>[] graph;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stk = new StringTokenizer(br.readLine());
        N = Integer.parseInt(stk.nextToken());
        M = Integer.parseInt(stk.nextToken());

        graph = new List[N + 1];
        for (int i = 1; i < N + 1; i++) {
            graph[i] = new ArrayList<>();
        }

        stk = new StringTokenizer(br.readLine());
        S = Integer.parseInt(stk.nextToken());
        E = Integer.parseInt(stk.nextToken());

        int h1, h2, k;
        for (int i = 0; i < M; i++) {
            stk = new StringTokenizer(br.readLine());
            h1 = Integer.parseInt(stk.nextToken());
            h2 = Integer.parseInt(stk.nextToken());
            k = Integer.parseInt(stk.nextToken());
            List<Integer> edge1 = new ArrayList<>();
            edge1.add(h2);
            edge1.add(k);
            graph[h1].add(edge1);

            List<Integer> edge2 = new ArrayList<>();
            edge2.add(h1);
            edge2.add(k);
            graph[h2].add(edge2);
        }

        int answer = 0;
        int left = 1, right = 1000001;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (bfs(mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
                answer = right;
            }
        }
        System.out.println(answer);
    }

    static boolean bfs(int weight) {
        boolean[] visited = new boolean[N + 1];
        visited[S] = true;
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(S);

        while (!q.isEmpty()) {
            int cur = q.poll();

            if (cur == E) {
                return true;
            }

            for (List<Integer> next : graph[cur]) {
                if (visited[next.get(0)]) {
                    continue;
                }
                if (next.get(1) < weight) {
                    continue;
                }
                visited[next.get(0)] = true;
                q.offer(next.get(0));
            }
        }
        return false;
    }
}