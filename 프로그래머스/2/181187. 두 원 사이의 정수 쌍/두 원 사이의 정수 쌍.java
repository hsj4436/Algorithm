class Solution {
    public long solution(int r1, int r2) {
        long answer = 0;
        
        for (int i = 1; i < r2 + 1; i++) {
            double l2 = Math.sqrt(Math.pow(r2, 2) - Math.pow(i, 2));
            double l1 = Math.sqrt(Math.pow(r1, 2) - Math.pow(i, 2));
            answer += (long)Math.floor(l2) - (long)Math.ceil(l1) + 1;
        }
        answer *= 4;
        
        return answer;
    }

}