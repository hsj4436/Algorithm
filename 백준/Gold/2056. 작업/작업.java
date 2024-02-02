import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static int[] times;
    static int[] pre;
    static List<Integer>[] post;
    static int[] finishTimes;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        times = new int[N + 1];
        pre = new int[N + 1];
        post = new ArrayList[N + 1];
        for (int i = 1; i < N + 1; i++) {
            post[i] = new ArrayList<>();
        }
        finishTimes = new int[N + 1];

        StringTokenizer stk;
        int preWorks = 0, preWork = 0;
        for (int i = 1; i < N + 1; i++) {
            stk = new StringTokenizer(br.readLine());
            times[i] = Integer.parseInt(stk.nextToken());
            preWorks = Integer.parseInt(stk.nextToken());
            pre[i] = preWorks;
            for (int j = 0; j < preWorks; j++) {
                preWork = Integer.parseInt(stk.nextToken());
                post[preWork].add(i);
            }
        }

        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 1; i < N + 1; i++) {
            if (pre[i] == 0) {
                q.add(i);
                finishTimes[i] = times[i];
            }
        }

        while (!q.isEmpty()) {
            int cur = q.peek();
            q.poll();

            for (int i = 0; i < post[cur].size(); i++) {
                int next = post[cur].get(i);
                finishTimes[next] = Math.max(finishTimes[next], finishTimes[cur] + times[next]);
                pre[next]--;
                if (pre[next] == 0) {
                    q.add(next);
                }
            }
        }

        int answer = 0;
        for (int i = 1; i < N + 1; i++) {
            answer = Math.max(answer, finishTimes[i]);
        }

        System.out.println(answer);
    }
}