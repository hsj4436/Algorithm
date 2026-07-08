class Solution {
    public int[] solution(int[][] arr) {
        int[] answer = getCompressed(arr, 0, 0, arr.length);
        return answer;
    }
    
    private static int[] getCompressed(int[][] arr, int x, int y, int n) {
        if (n == 1) {
            if (arr[x][y] == 0) {
                return new int[]{1, 0};
            } else {
                return new int[]{0, 1};
            }
        }
        
        int[] leftTop     = getCompressed(arr, x        , y        , n / 2);
        int[] rightTop    = getCompressed(arr, x        , y + n / 2, n / 2);
        int[] leftBottom  = getCompressed(arr, x + n / 2, y        , n / 2);
        int[] rightBottom = getCompressed(arr, x + n / 2, y + n / 2, n / 2);
        
        if ((leftTop[0] + rightTop[0] + leftBottom[0] + rightBottom[0] == 4)
         && (leftTop[1] + rightTop[1] + leftBottom[1] + rightBottom[1] == 0)) {
            return new int[]{1, 0};    
        }
        if ((leftTop[0] + rightTop[0] + leftBottom[0] + rightBottom[0] == 0)
         && (leftTop[1] + rightTop[1] + leftBottom[1] + rightBottom[1] == 4)) {
            return new int[]{0, 1};
        }
        return new int[]{leftTop[0] + rightTop[0] + leftBottom[0] + rightBottom[0]
                       , leftTop[1] + rightTop[1] + leftBottom[1] + rightBottom[1]};
    }
}