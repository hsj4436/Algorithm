class Solution {
    public int solution(int[][] signals) {
        int answer = -1;
        
        int[] cycle = new int[signals.length];
        for (int i = 0; i < signals.length; i++) {
            cycle[i] = signals[i][0] + signals[i][1] + signals[i][2];
        }
        int max = 1;
        for (int i = 0; i < cycle.length; i++) {
            max *= cycle[i];
        }
        
        for (int i = 1; i < max + 1; i++) {
            int count = 0;
            for (int j = 0; j < cycle.length; j++) {
                if (i < cycle[j]) {
                    if (signals[j][0] < i && i <= signals[j][0] + signals[j][1]) {
                        count++;
                    }   
                } else {
                    if (signals[j][0] < i % cycle[j] && i % cycle[j] <= signals[j][0] + signals[j][1]) {
                        count++;
                    }
                }
            }
            if (count == signals.length) {
                return i;
            }
        }
        
        return answer;
    }
}