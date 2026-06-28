class Solution {
    public int solution(int sticker[]) {
        int answer = 0;
        int N = sticker.length;
        int[][] dpZero = new int[N][2];
        int[][] dpOne = new int[N][2];
        if (N == 1) {
            return sticker[0];    
        } else if (N == 2) {
            return Math.max(sticker[0], sticker[1]);
        }
        dpZero[0][0] = 0;
        dpZero[0][1] = sticker[0];
        dpOne[0][0] = 0;
        dpOne[0][1] = 0;
        dpOne[1][0] = 0;
        dpOne[1][1] = sticker[1];    
        
        for (int i = 1; i < N; i++) {
            dpZero[i][0] = Math.max(dpZero[i - 1][0], dpZero[i - 1][1]);
            dpZero[i][1] = Math.max(dpZero[(i - 2 + N) % N][1] + sticker[i], Math.max(dpZero[(i - 2 + N) % N][0] + sticker[i], dpZero[i - 1][0] + sticker[i]));
        }
        for (int i = 2; i < N; i++) {
            dpOne[i][0] = Math.max(dpOne[i - 1][0], dpOne[i - 1][1]);
            dpOne[i][1] = Math.max(dpOne[i - 2][1] + sticker[i], Math.max(dpOne[i - 2][0] + sticker[i], dpOne[i - 1][0] + sticker[i]));
        }
        
        answer = Math.max(dpZero[N - 1][0], dpOne[N - 1][1]);

        return answer;
    }
}