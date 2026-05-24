import java.util.*;

class Solution {
    public int solution(int n, int k, int[] enemy) {
        int answer = 0;
        
        if (k >= enemy.length) {
            return enemy.length;
        }
        
        int left = 0, right = enemy.length;
        while (left < right) {
            int mid = (left + right) / 2;
            
            long eliminated = 0;
            int[] slicedEnemy = Arrays.copyOfRange(enemy, 0, mid + 1);
            Arrays.sort(slicedEnemy);
            int kCount = 0;
            for (int i = slicedEnemy.length - 1; i > -1; i--) {
                if (kCount < k) {
                    kCount++;
                    continue;
                }
                eliminated += slicedEnemy[i];
            }
            
            if (eliminated <= n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
}