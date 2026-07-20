class Solution {
    public int solution(int n) {
        int answer = 0;
        int[] sum = new int[n + 1];
        sum[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            sum[i] = sum[i - 1] + i;
        }
        
        int left = 0, right = 1;
        while (left <= n) {
           if (sum[right] - sum[left] < n) {
                if (right + 1 <= n) {
                    right++;    
                } else {
                    left++;
                }
            } else if (sum[right] - sum[left] == n) {
                answer++;
                if (right + 1 <= n) {
                    right++;    
                } else {
                    left++;
                }
            } else {
                left++;
            }
        }
        return answer;
    }
}