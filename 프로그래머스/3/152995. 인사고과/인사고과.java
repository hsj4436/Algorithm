import java.util.*;

class Solution {
    public int solution(int[][] scores) {
        int answer = 0;
        List<int[]> score = new ArrayList<>();
        score.add(new int[]{scores[0][0], scores[0][1], 1});
        for (int i = 1; i < scores.length; i++) {
            score.add(new int[]{scores[i][0], scores[i][1], 0});
        }
        score.sort((s1, s2) -> {
            return (s2[0] + s2[1]) - (s1[0] + s1[1]);
        });
        
        int before = 200001, rank = 0;
        for (int i = 0; i < score.size(); i++) {
            if (score.get(i)[0] + score.get(i)[1] < before) {
                boolean pass = true;
                for (int j = 0; j < i; j++) {
                    if (score.get(i)[0] < score.get(j)[0] && score.get(i)[1] < score.get(j)[1]) {
                        pass = false;
                        break;
                    }
                }
                if (pass) {
                    rank++;
                    if (score.get(i)[2] == 1) {
                        return rank;
                    }
                } else {
                    if (score.get(i)[2] == 1) {
                        return -1;
                    }
                }
            }
        }
        
        return answer;
    }
}