import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        Arrays.sort(citations);
        
        int left = 0, right = citations[citations.length - 1];
        while (left <= right) {
            int mid = (left + right) / 2;
            
            int count = 0;
            for (int i = 0; i < citations.length; i++) {
                if (citations[i] >= mid) {
                    count = citations.length - i;
                    break;
                }
            }
            
            if (count >= mid) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return answer;
    }
}