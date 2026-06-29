import java.util.*;

class Solution {
    
    private static final int INF = 987654321;
    
    public int solution(int x, int y, int n) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{x, 0});
        int[] dp = new int[y + 1];
        Arrays.fill(dp, INF);
        dp[x] = 0;
        
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            
            if (cur[0] == y) {
                return cur[1];
            }
            
            if (cur[0] + n <= y && cur[1] + 1 < dp[cur[0] + n]) {
                q.add(new int[]{cur[0] + n, cur[1] + 1});
                dp[cur[0] + n] = cur[1] + 1;
            }
            
            if (cur[0] * 2 <= y && cur[1] + 1 < dp[cur[0] * 2]) {
                q.add(new int[]{cur[0] * 2, cur[1] + 1});
                dp[cur[0] * 2] = cur[1] + 1;
            }
            
            if (cur[0] * 3 <= y && cur[1] + 1 < dp[cur[0] * 3]) {
                q.add(new int[]{cur[0] * 3, cur[1] + 1});
                dp[cur[0] * 3] = cur[1] + 1;
            }
        }
        
        return -1;
    }
}