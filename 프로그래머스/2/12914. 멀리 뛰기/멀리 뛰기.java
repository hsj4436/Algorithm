class Solution {
    
    private static final long MOD = 1234567;
    
    public long solution(int n) {
        if (n == 1) {
            return 1;
        }
        long[] steps = new long[n + 1];
        steps[1] = 1;
        steps[2] = 2;
        for (int i = 3; i < n + 1; i++) {
            steps[i] = (steps[i - 1] % MOD + steps[i - 2] % MOD) % MOD;
        }
        
        return steps[n];
    }
}