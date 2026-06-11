import java.util.*;

class Solution {
    
    private static List<String> nonSpoiler = new ArrayList<>();
    private static List<String> importantWord = new ArrayList<>();
    
    public int solution(String message, int[][] spoiler_ranges) {
        int answer = 0;
        
        String blockedMessage = new String(message);
        for (int i = 0; i < spoiler_ranges.length; i++) {
            int left = spoiler_ranges[i][0];
            int right = spoiler_ranges[i][1];
            for (int j = left; j < right + 1; j++) {
                if (blockedMessage.charAt(j) == ' ') {
                    continue;
                }
                blockedMessage = blockedMessage.substring(0, j) + '_' + blockedMessage.substring(j + 1);
            }
        }
        String[] blockedWords = blockedMessage.split(" ");
        for (String word : blockedWords) {
            if (!word.contains("_")) {
                nonSpoiler.add(word);
            }    
        }
        
        String[] words = message.split(" ");
        for (int i = 0; i < words.length; i++) {
            if (blockedWords[i].contains("_")) {
                if (!nonSpoiler.contains(words[i]) && !importantWord.contains(words[i])) {
                    answer++;
                    importantWord.add(words[i]);
                }
            }
        }
        
        return answer;
    }
}