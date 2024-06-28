import java.io.*;
import java.util.*;

public class Main {
    
    private static int N = 0;
    private static int M = 0;
    private static int[] distance;
    private static List<Pair>[] graph;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        N = Integer.parseInt(stk.nextToken());
        M = Integer.parseInt(stk.nextToken());
        graph = new List[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<Pair>();
        }
        
        int A, B, C;
        for (int i = 0; i < M; i++) {
            stk = new StringTokenizer(br.readLine());
            A = Integer.parseInt(stk.nextToken());
            B = Integer.parseInt(stk.nextToken());
            C = Integer.parseInt(stk.nextToken());
            graph[A].add(new Pair(B, C));
            graph[B].add(new Pair(A, C));
        }
        
        distance = new int[N + 1];
        Arrays.fill(distance, 987654321);
        Map<Integer, Pair> answer = new HashMap<>();
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
        pq.add(new Pair(1, 0));
        distance[1] = 0;
        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int cur = p.to;
            int dist = p.cost;
            
            for (Pair next : graph[cur]) {
                if (next.cost + dist < distance[next.to]) {
                    distance[next.to] = next.cost + dist;
                    pq.add(new Pair(next.to, distance[next.to]));
                    if (Objects.isNull(answer.get(next.to))) {
                        answer.put(next.to, new Pair(cur, next.cost));
                    } else if (next.cost < answer.get(next.to).cost) {
                        answer.put(next.to, new Pair(cur, next.cost));
                    }
                }
            }
        }
        
        System.out.println(answer.size());
        for (Integer from : answer.keySet()) {
            Pair p = answer.get(from);
            System.out.println(from + " " + p.to);
        }
    }
    
    private static class Pair implements Comparable<Pair> {
        int to;
        int cost;
        Pair() {}
        Pair(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
        
        @Override
        public int compareTo(Pair p) {
            return this.cost - p.cost;
        }
    }
}