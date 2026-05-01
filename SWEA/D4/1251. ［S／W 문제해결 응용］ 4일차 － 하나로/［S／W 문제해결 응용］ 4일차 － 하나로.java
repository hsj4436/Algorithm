import java.io.*;
import java.util.*;

public class Solution {

    static class Edge implements Comparable<Edge> {
        int to;
        double cost;

        public Edge(int to, double cost) {
            this.to = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge o) {
            return Double.compare(this.cost, o.cost);
        }
    }

    static int TC;
    static int N;
    static int[] xPoints;
    static int[] yPoints;
    static double E;
    static List<Edge>[] graph;
    static boolean[] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        TC = Integer.parseInt(br.readLine());

        for (int i = 0; i < TC; i++) {
            solve(br, i + 1);
        }
    }

    static void solve(BufferedReader br, int tc) throws Exception {
        N = Integer.parseInt(br.readLine());
        xPoints = new int[N];
        yPoints = new int[N];
        graph = new List[N];
        visited = new boolean[N];
        for (int i = 0; i < N; i++) {
            graph[i] = new ArrayList<>();
        }

        StringTokenizer stk = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            xPoints[i] = Integer.parseInt(stk.nextToken());
        }
        stk = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            yPoints[i] = Integer.parseInt(stk.nextToken());
        }
        E = Double.parseDouble(br.readLine());

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }
                double distance = Math.pow(xPoints[i] - xPoints[j], 2) + Math.pow(yPoints[i] - yPoints[j], 2);
                graph[i].add(new Edge(j, distance * E));
            }
        }

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.offer(new Edge(0, 0.0));
        int selectedVertices = 0;
        double answer = 0;
        while (!pq.isEmpty()) {
            Edge e = pq.poll();

            if (visited[e.to]) {
                continue;
            }

            visited[e.to] = true;
            answer += e.cost;
            selectedVertices++;

            if (selectedVertices == N) {
                break;
            }

            for (Edge next : graph[e.to]) {
                if (visited[next.to]) {
                    continue;
                }
                pq.offer(next);
            }
        }

        System.out.println("#" + tc + " " + Math.round(answer));
    }
}