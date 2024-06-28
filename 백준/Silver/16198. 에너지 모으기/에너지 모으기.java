import java.io.*;
import java.util.*;

public class Main {
    private static int N = 0;
    private static int answer = 0;
    
    private static void backTrack(int energy, List<Integer> balls) {
        if (balls.size() == 2) {
            answer = Math.max(answer, energy);
            return;
        }
        
        for (int i = 1; i < balls.size() - 1; i++) {
            List<Integer> ballsCopy = new LinkedList<>(balls);
            int addedEnergy = ballsCopy.get(i - 1) * ballsCopy.get(i + 1);
            ballsCopy.remove(i);
            backTrack(energy + addedEnergy, ballsCopy);
        }
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        List<Integer> balls = new LinkedList<>();
        StringTokenizer stk = new StringTokenizer(br.readLine());
        while (stk.hasMoreTokens()) {
            balls.add(Integer.parseInt(stk.nextToken()));
        }
        
        backTrack(0, balls);
        
        System.out.println(answer);
    }
    
    
}