import java.util.*;

class Solution {
    public long[] solution(int n, long left, long right) {
        long[] answer = {};
        List<Long> ans = new ArrayList<>();
        for (long i = left; i < right + 1; i++) {
            long r = i / n;
            long c = i % n;
            if (r <= c) {
                ans.add(c + 1);
            } else {
                ans.add(r + 1);
            }
        }
        answer = ans.stream().mapToLong(Long::longValue).toArray();
        return answer;
    }
}