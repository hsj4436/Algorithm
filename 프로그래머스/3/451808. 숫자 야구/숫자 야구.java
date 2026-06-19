import java.util.function.Function;
import java.util.*;

class Solution {

    public int solution(int n, Function<Integer, String> submit) {
        List<Integer> pool = new ArrayList<>();
        permutation(pool);
        while (pool.size() != 1) {
            int num = pool.get(0);
            String result = submit.apply(num);
            pool = remake(pool, num, result.charAt(0) - '0', result.charAt(3) - '0');
        }
            
        return pool.get(0);
    }
    
    private static void permutation(List<Integer> pool) {
        for (int i = 1; i < 10; i++) {
            for (int j = 1; j < 10; j++) {
                if (i == j) continue;
                for (int k = 1; k < 10; k++) {
                    if (i == k || j == k) continue;
                    for (int l = 1; l < 10; l++) {
                        if (i == l || j == l || k == l) continue;
                        pool.add(i * 1000 + j * 100 + k * 10 + l);
                    }
                }
            }
        }
    }
    
    private static List<Integer> remake(List<Integer> pool, int pwd, int S, int B) {
        List<Integer> newPool = new ArrayList<>();
        String strPwd = Integer.toString(pwd);
        for (Integer num : pool) {
            String strNum = Integer.toString(num);
            int strikes = 0, balls = 0;
            for (int i = 0; i < 4; i++) {
                if (strNum.charAt(i) == strPwd.charAt(i)) {
                    strikes++;
                } else {
                    boolean isContains = false;
                    for (int j = 0; j < 4; j++) {
                        if (strPwd.charAt(j) == strNum.charAt(i)) {
                            isContains = true;
                            break;
                        }
                    }
                    if (isContains) {
                        balls++;   
                    }
                }
            }
            if (S == strikes && B == balls) {
                newPool.add(num);
            }
        }
        return newPool;
    }
}