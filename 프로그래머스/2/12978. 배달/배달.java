import java.util.*;

class Solution {
    
    static final int INF = 987654321;
    
    static class Node implements Comparable<Node> {
        int to;
        int cost;
        Node(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.cost, o.cost);
        }
    }
    
    public int solution(int N, int[][] road, int K) {
        int answer = 0;

        List<List<Node>> graph = new ArrayList<>();
        int[] dist = new int[N + 1];
        
        for (int i = 0; i < N + 1; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < road.length; i++) {
            graph.get(road[i][0]).add(new Node(road[i][1], road[i][2]));
            graph.get(road[i][1]).add(new Node(road[i][0], road[i][2]));
        }
        
        dijkstra(N, 1, graph, dist);
        
        for (int i = 1; i < N + 1; i++) {
            if (dist[i] <= K) {
                answer++;
            }
        }
        
        return answer;
    }
    
    static void dijkstra(int N, int start, List<List<Node>> graph, int[] dist) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        Arrays.fill(dist, INF);
        dist[1] = 0;
        pq.offer(new Node(1, 0));
        
        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            
            int to = cur.to;
            int currentCost = cur.cost;
            
            if (dist[to] < currentCost) {
                continue;
            }
            for (Node next : graph.get(to)) {
                int nextNode = next.to;
                int newCost = dist[to] + next.cost;
                if (newCost < dist[nextNode]) {
                    dist[nextNode] = newCost;
                    pq.offer(new Node(nextNode, newCost));
                }
            }
        }
    }
}