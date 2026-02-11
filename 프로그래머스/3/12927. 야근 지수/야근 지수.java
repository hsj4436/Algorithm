import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i : works) {
            pq.add(i);
        }
        
        while (n > 0 && !pq.isEmpty()) {
            if (pq.peek() == 0) {
                break;
            }
            pq.add(pq.poll() - 1);
            n--;
        }
        
        while (!pq.isEmpty()) {
            int front = pq.poll();
            answer += front * front;
        }
        
        return answer;
    }
}