import java.util.*;

class Solution {
    public String solution(String s) {
        int[] arr = Arrays.stream(s.split(" ")).mapToInt(Integer::parseInt).toArray();
        List<Integer> ls = new ArrayList<>();
        for (int i : arr) {
            ls.add(i);
        }
        
        return String.valueOf(Collections.min(ls)) + " " + String.valueOf(Collections.max(ls));
    }
}