import java.util.*;

class Solution {
    
    static List<Integer> ans = new ArrayList<>();
    
    public int[] solution(int[] numbers) {
        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                if (!ans.contains(numbers[i] + numbers[j])) {
                    ans.add(numbers[i] + numbers[j]);
                }
            }
        }
        Collections.sort(ans);
        return ans.stream().mapToInt(i -> i).toArray();
    }
    
}