class Solution {
    
    public long solution(int n, int[] times) {
        long answer = 0;
        long min = 1000000001;
        for (int i = 0; i < times.length; i++) {
            min = Math.min(min, times[i]);
        }
        long left = 0, right = min * n;
        while (left < right) {
            long mid = left + (right - left) / 2;
            
            if (checkPossibility(n, times, mid)) {
                answer = mid;
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return answer;
    }
    
    static boolean checkPossibility(int n, int[] times, long t) {
        long passed = 0;
        for (int i = 0; i < times.length; i++) {
            passed += t / times[i];
        }
        
        return passed >= n;
    }
}