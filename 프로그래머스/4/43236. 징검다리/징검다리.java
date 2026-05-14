import java.util.*;

class Solution {
    public int solution(int distance, int[] rocks, int n) {
        int answer = 0;
        
        Arrays.sort(rocks);
        
        int left = 0, right = distance;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            boolean possible = true;
            int erased = 0;
            int lastPoint = 0;
            for (int i = 0; i < rocks.length; i++) {
                if (rocks[i] - lastPoint < mid) {
                    erased++;
                    if (erased > n) {
                        possible = false;
                        break;
                    }
                } else {
                    lastPoint = rocks[i];
                }
            }
            if (distance - lastPoint < mid) {
                erased++;
                if (erased > n) {
                    possible = false;
                }
            }
            if (possible) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return answer;
    }
}