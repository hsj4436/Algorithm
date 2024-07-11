import java.io.*;
import java.util.*;

class Solution {
    
    static Map<String, Integer> term = new TreeMap<>();
    
    public int[] solution(String today, String[] terms, String[] privacies) {
        int[] answer = {};
        int convertedToday = toDay(today);
        for (int i = 0; i < terms.length; i++) {
            StringTokenizer stk = new StringTokenizer(terms[i]);
            term.put(stk.nextToken(), Integer.parseInt(stk.nextToken()));
        }
        List<Integer> privacyList = new ArrayList<>();
        for (int i = 0; i < privacies.length; i++) {
            StringTokenizer stk = new StringTokenizer(privacies[i]);
            int day = toDay(stk.nextToken());
            String termKey = stk.nextToken();
            int termDay = term.get(termKey) * 28;
            if (day + termDay - 1 < convertedToday) {
                privacyList.add(i + 1);
            }
        }
        
        answer = new int[privacyList.size()];
        for (int i = 0; i < privacyList.size(); i++) {
            answer[i] = privacyList.get(i);
        }
        
        return answer;
    }
    
    static int toDay(String date) {
        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8, 10));
        return year * 12 * 28 + month * 28 + day;
    }
}