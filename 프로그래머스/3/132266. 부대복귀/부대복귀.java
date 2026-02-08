import java.util.*;

class Solution {
    
    private static final int INF = 987654321;
    
    private List<Integer>[] graph;
    private Queue<int[]> q; // {current position, used time}
    private boolean[] visited;
    private int[] fromDestination;
    
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length];
        graph = new ArrayList[n + 1];
        for (int i = 1; i < n + 1; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < roads.length; i++) {
            int a = roads[i][0];
            int b = roads[i][1];
            graph[a].add(b);
            graph[b].add(a);
        }
        
        visited = new boolean[n + 1];
        visited[0] = true;
        visited[destination] = true;
        
        fromDestination = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            fromDestination[i] = INF;
        }
        
        fromDestination[destination] = 0;
        q = new LinkedList<>();
        q.add(new int[]{destination, 0});

        while (!q.isEmpty()) {
            int[] cur = q.poll();

            for (int next : graph[cur[0]]) {
                if (visited[next]) {
                    continue;
                }
                visited[next] = true;
                q.add(new int[]{next, cur[1] + 1});
                fromDestination[next] = cur[1] + 1;
            }
        }
        
        for (int i = 0; i < sources.length; i++) {
            if (fromDestination[sources[i]] == INF) {
                answer[i] = -1;
            } else {
                answer[i] = fromDestination[sources[i]];
            }
        }
        
        return answer;
    }
}