import java.util.*;

class Solution {
    
    static List<Integer>[][][][] infos = new ArrayList[3][2][2][2];
    
    public int[] solution(String[] info, String[] query) {
        int[] answer = new int[query.length];
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        infos[i][j][k][l] = new ArrayList<>();
                    }
                }
            }
        }
        
        String[][] splittedInfo = new String[info.length][5];
        for (int i = 0; i < info.length; i++) {
            splittedInfo[i] = info[i].split(" ");
            int idx1 = 0, idx2 = 0, idx3 = 0, idx4 = 0;
            if (splittedInfo[i][0].equals("cpp")) {
                idx1 = 0;
            } else if (splittedInfo[i][0].equals("java")) {
                idx1 = 1;   
            } else {
                idx1 = 2;
            }
            
            if (splittedInfo[i][1].equals("backend")) {
                idx2 = 0;
            } else {
                idx2 = 1;
            }
            
            if (splittedInfo[i][2].equals("junior")) {
                idx3 = 0;
            } else {
                idx3 = 1;
            }
            
            if (splittedInfo[i][3].equals("chicken")) {
                idx4 = 0;
            } else {
                idx4 = 1;
            }
            infos[idx1][idx2][idx3][idx4].add(Integer.parseInt(splittedInfo[i][4]));
        }
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        Collections.sort(infos[i][j][k][l]);
                    }
                }
            }
        }
        
        for (int i = 0; i < query.length; i++) {
            String[] splittedQuery = query[i].replace("and ", "").split(" ");
            answer[i] = executeQuery(splittedQuery);
        }
        
        return answer;
    }
    
    static int executeQuery(String[] splittedQuery) {
        int count = 0;
        int target = Integer.parseInt(splittedQuery[4]);
        for (int i = 0; i < 3; i++) {
            if (i == 0 && !(splittedQuery[0].equals("cpp") || splittedQuery[0].equals("-"))) {
                continue;
            }
            if (i == 1 && !(splittedQuery[0].equals("java") || splittedQuery[0].equals("-"))) {
                continue;
            }
            if (i == 2 && !(splittedQuery[0].equals("python") || splittedQuery[0].equals("-"))) {
                continue;
            }
            for (int j = 0; j < 2; j++) {
                if (j == 0 && !(splittedQuery[1].equals("backend") || splittedQuery[1].equals("-"))) {
                    continue;
                }
                if (j == 1 && !(splittedQuery[1].equals("frontend") || splittedQuery[1].equals("-"))) {
                    continue;
                }
                for (int k = 0; k < 2; k++) {
                    if (k == 0 && !(splittedQuery[2].equals("junior") || splittedQuery[2].equals("-"))) {
                        continue;
                    }
                    if (k == 1 && !(splittedQuery[2].equals("senior") || splittedQuery[2].equals("-"))) {
                        continue;
                    }
                    for (int l = 0; l < 2; l++) {
                        if (l == 0 && !(splittedQuery[3].equals("chicken") || splittedQuery[3].equals("-"))) {
                            continue;
                        }
                        if (l == 1 && !(splittedQuery[3].equals("pizza") || splittedQuery[3].equals("-"))) {
                            continue;
                        }
                        List<Integer> scores = infos[i][j][k][l];
                        int left = 0, right = scores.size();
                        while (left < right) {
                            int mid = left + (right - left) / 2;
                            if (scores.get(mid) >= target) {
                                right = mid;
                            } else {
                                left = mid + 1;
                            }
                        }
                        count += scores.size() - left;
                    }
                }
            }
        }
        
        return count;
    }
}