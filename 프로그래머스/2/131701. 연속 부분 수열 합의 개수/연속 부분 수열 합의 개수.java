import java.util.*;

class Solution {
    
    private Set<Integer> set = new HashSet<>();
    private int[] sums;
    
    public int solution(int[] elements) {
        sums = new int[elements.length * 2 + 1];
        for (int i = 0; i < elements.length * 2; i++) {
            sums[i + 1] = sums[i] + elements[i % elements.length];
        }
        
        for (int lengthOfSeries = 1; lengthOfSeries < elements.length; lengthOfSeries++) {
            for (int j = 1; j < elements.length + 1; j++) {
                set.add(sums[j + lengthOfSeries] - sums[j]);
            }
        } 
        
        return set.size() + 1;
    }
    
}