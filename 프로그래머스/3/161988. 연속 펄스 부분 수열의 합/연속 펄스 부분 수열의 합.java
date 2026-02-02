class Solution {
    
    private int N;
    private long[][] fromPositive; // [i][0] sum of 0 ~ i, [i][1] min sum of 0 ~ i
    private long[][] fromNegative;
    
    public long solution(int[] sequence) {
        N = sequence.length;
        fromPositive = new long[N][2];
        fromNegative = new long[N][2];
        
        fromPositive[0][0] = sequence[0];
        fromPositive[0][1] = sequence[0];
        fromNegative[0][0] = sequence[0] * -1;
        fromNegative[0][1] = sequence[0] * -1;
        
        for (int i = 1; i < N; i++) {
            long pulseSegment = 1;
            //positive
            if ((i + 1) % 2 == 0) {
                pulseSegment *= -1;
            }
            fromPositive[i][0] = fromPositive[i - 1][0] + sequence[i] * pulseSegment;
            fromPositive[i][1] = Math.min(fromPositive[i - 1][1], fromPositive[i][0]);
            
            pulseSegment = 1;
            //negative
            if ((i + 1) % 2 == 1) {
                pulseSegment *= -1;
            }
            fromNegative[i][0] = fromNegative[i - 1][0] + sequence[i] * pulseSegment;
            fromNegative[i][1] = Math.min(fromNegative[i - 1][1], fromNegative[i][0]);
        }
        
        long answer = 0;
        for (int i = 0; i < N; i++) {
            answer = Math.max(answer, fromPositive[i][0]);
            answer = Math.max(answer, fromPositive[i][0] - fromPositive[i][1]);
            
            answer = Math.max(answer, fromNegative[i][0]);
            answer = Math.max(answer, fromNegative[i][0] - fromNegative[i][1]);
        }
        
        return answer;
    }
}