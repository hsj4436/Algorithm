import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] turnCount = new int[n];
        List<String> used = new ArrayList<>();
        String past = null;
        for (int i = 0; i < words.length; i++) {
            turnCount[i % n]++;
            
            if (used.contains(words[i])) {
                return new int[]{(i % n) + 1, turnCount[i % n]};
            } else if (past != null && past.charAt(past.length() - 1) != words[i].charAt(0)) {
                return new int[]{(i % n) + 1, turnCount[i % n]};
            }
            past = words[i];
            used.add(words[i]);
        }
        
        return new int[]{0, 0};
    }
}