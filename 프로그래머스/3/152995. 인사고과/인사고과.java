import java.util.*;

class Solution {
    public int solution(int[][] scores) {
        int answer = 1;
        
        int[] wanho = scores[0];
        int maxCoworkerScore = 0;
        
        Arrays.sort(scores, (s1, s2) -> {
            return s1[0] == s2[0] ? s1[1] - s2[1] : s2[0] - s1[0];
        });
        
        for(int[] score : scores) {
            if (maxCoworkerScore <= score[1]) {
                maxCoworkerScore = score[1];
                if (score[0] + score[1] > wanho[0] + wanho[1]) {
                    answer++;
                }
            } else {
                if (score.equals(wanho)) {
                    return -1;
                }
            }
        }
        
        return answer;
    }
}