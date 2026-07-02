import java.util.*;

class Solution {
    public String solution(String s) {
        String[] arr = s.split(" ");
        int min = Integer.parseInt(arr[0]);
        int max = min;
        for (int i = 1; i < arr.length; i++) {
            min = Math.min(min, Integer.parseInt(arr[i]));
            max = Math.max(max, Integer.parseInt(arr[i]));
        }
        
        return min + " " + max;
    }
}