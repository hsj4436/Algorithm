import java.util.*;

class Solution {
    public int solution(int[] citations) {
        Arrays.sort(citations);
        
        int left = 0, right = citations[citations.length - 1];
        while (left <= right) {
            int mid = (left + right) / 2;
            
            int count = citations.length - lowerBound(citations, mid);
            if (count < mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return right;
    }
    
    static int lowerBound(int[] citations, int target) {
        int left = 0, right = citations.length;
        while (left < right) {
            int mid = (left + right) / 2;
            
            if (citations[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}