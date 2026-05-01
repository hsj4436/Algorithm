import java.util.*;

class Solution {
 
    static class Edge implements Comparable<Edge> {
        int from;
        int to;
        int cost;
        public Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
        @Override
        public int compareTo(Edge o) {
            return this.cost - o.cost;
        }
    }
    
    static int[] parents;
    
    public int solution(int n, int[][] costs) {
        int answer = 0;
        parents = new int[n];
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        
        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < costs.length; i++) {
            edges.add(new Edge(costs[i][0], costs[i][1], costs[i][2]));
        }
        Collections.sort(edges);
        
        int selectedVertices = 0;
        for (Edge edge : edges) {
            if (findParent(edge.from) == findParent(edge.to)) {
                continue;
            }
            selectedVertices++;
            answer += edge.cost;
            union(edge.from, edge.to);
            
            if (selectedVertices == n - 1) {
                break;
            }
        }
        
        return answer;
    }
    
    static int findParent(int target) {
        if (parents[target] == target) {
            return parents[target];
        }
        
        return parents[target] = findParent(parents[target]);
    }
    
    static void union(int a, int b) {
        int parentA = findParent(a);
        int parentB = findParent(b);
        
        if (parents[parentA] < parents[parentB]) {
            parents[parentB] = parentA;
        } else {
            parents[parentA] = parentB;
        }
    }
}