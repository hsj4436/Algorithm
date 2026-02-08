import java.util.*;

class Solution {
    
    private List<Integer>[] graph;
    private Queue<int[]> q; // {current position, used time}
    private boolean[] visited;
    
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
        
        for (int i = 0; i < sources.length; i++) {
            answer[i] = -1;
            if (sources[i] == destination) {
                answer[i] = 0;
                continue;
            }
            visited = new boolean[n + 1];
            visited[0] = true;
            visited[sources[i]] = true;
            q = new LinkedList<>();
            q.add(new int[]{sources[i], 0});
            
            while (!q.isEmpty()) {
                int[] cur = q.poll();
                
                boolean isEnd = false;
                for (int next : graph[cur[0]]) {
                    if (visited[next]) {
                        continue;
                    }
                    visited[next] = true;
                    q.add(new int[]{next, cur[1] + 1});
                    if (next == destination) {
                        isEnd = true;
                        answer[i] = cur[1] + 1;
                        break;
                    }
                }
                if (isEnd) {
                    break;
                }
            }
        }
        
        
        
        return answer;
    }
}