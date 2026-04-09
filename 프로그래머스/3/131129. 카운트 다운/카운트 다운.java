class Solution {
    
    private int[][] track; // [score][0] # of threw, [score][1] sum of single and bull
    
    private void dfs(int target, int threw, int singleAndBull) {
        if (target == 0) {
            return;
        }
        for (int i = 1; i < 21; i++) {
            if (target - 50 >= 0) {
                if (threw + 1 < track[target - 50][0] 
                   || (threw + 1 == track[target - 50][0] && singleAndBull + 1 > track[target - 50][1])) {
                        track[target - 50] = new int[]{threw + 1, singleAndBull + 1};
                        dfs(target - 50, threw + 1, singleAndBull + 1);
                    }
            }
            for (int j = 1; j < 4; j++) {
                if (target - i * j < 0) {
                    continue;
                }
                if (j == 1) {
                    if (threw + 1 < track[target - i * j][0] 
                       || (threw + 1 == track[target - i * j][0] && singleAndBull + 1 > track[target - i * j][1])) {
                        track[target - i * j] = new int[]{threw + 1, singleAndBull + 1};
                        dfs(target - i * j, threw + 1, singleAndBull + 1);
                    }
                } else {
                    if (threw + 1 < track[target - i * j][0] 
                       || (threw + 1 == track[target - i * j][0] && singleAndBull > track[target - i * j][1])) {
                        track[target - i * j] = new int[]{threw + 1, singleAndBull};
                        dfs(target - i * j, threw + 1, singleAndBull);
                    }
                }
            }
        }
    }
    
    public int[] solution(int target) {
        int[] answer = {};
        
        track = new int[target + 1][2];
        for (int i = 0; i < target + 1; i++) {
            track[i][0] = 100001;
            track[i][1] = 100001;
        }
        track[target][0] = 0;
        track[target][1] = 0;
        dfs(target, 0, 0);
        
        answer = track[0];
        
        return answer;
    }
}