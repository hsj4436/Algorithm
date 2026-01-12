class Solution {
    
    private int[] servers;
    
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        
        servers = new int[players.length];
        for (int i = 0; i < players.length; i++) {
            int needs = (players[i] / m) - servers[i];
            
            if (needs > 0) {
                for (int j = i; j < (i + k >= servers.length ? servers.length : i + k); j++) {
                    servers[j] += needs;
                }
                answer += needs;
            }
        }
        
        return answer;
    }
}