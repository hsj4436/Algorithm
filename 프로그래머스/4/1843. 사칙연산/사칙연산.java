class Solution {
    
    private int N;
    private int[][] maxDp;
    private int[][] minDp;
    
    public int solution(String arr[]) {
        N = arr.length / 2 + 1;
        maxDp = new int[N][N];
        minDp = new int[N][N];
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    maxDp[i][j] = Integer.parseInt(arr[i * 2]);
                    minDp[i][j] = Integer.parseInt(arr[i * 2]);
                } else {
                    maxDp[i][j] = -987654321;
                    minDp[i][j] = 987654321;    
                }
            }
        }
        
        for (int step = 1; step < N; step++) {
            for (int i = 0; i < N - step; i++) {
                int j = i + step;
                for (int k = i; k < j; k++) {
                    if ("+".equals(arr[k * 2 + 1])) {
                        maxDp[i][j] = Math.max(maxDp[i][j], maxDp[i][k] + maxDp[k + 1][j]);
                        minDp[i][j] = Math.min(minDp[i][j], minDp[i][k] + minDp[k + 1][j]);
                    } else {
                        maxDp[i][j] = Math.max(maxDp[i][j], maxDp[i][k] - minDp[k + 1][j]);
                        minDp[i][j] = Math.min(minDp[i][j], minDp[i][k] - maxDp[k + 1][j]);
                    }           
                }
            }
        }
        
        return maxDp[0][N - 1];
    }
}