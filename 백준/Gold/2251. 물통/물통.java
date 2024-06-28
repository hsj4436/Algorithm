import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        int limitA, limitB, limitC;
        limitA = Integer.parseInt(stk.nextToken());
        limitB = Integer.parseInt(stk.nextToken());
        limitC = Integer.parseInt(stk.nextToken());
        boolean[][][] visited = new boolean[limitA + 1][limitB + 1][limitC + 1];
        Deque<State> q = new LinkedList<>();
        List<Integer> answer = new ArrayList<>();
        visited[0][0][limitC] = true;
        q.add(new State(0, 0, limitC));
        
        while (!q.isEmpty()) {
            State cur = q.poll();
            if (cur.A == 0) {
                answer.add(cur.C);    
            }
            
            if (cur.A != 0) {
                if (cur.B < limitB) {
                    if (cur.A + cur.B > limitB) {
                        State next = new State(cur.A, cur.B, cur.C);
                        next.A -= limitB - cur.B;
                        next.B = limitB;
                        if (!visited[next.A][next.B][next.C]) {
                            visited[next.A][next.B][next.C] = true;
                            q.add(next);
                        }
                    } else {
                        State next = new State(cur.A, cur.B, cur.C);
                        next.A = 0;
                        next.B += cur.A;
                        if (!visited[next.A][next.B][next.C]) {
                            visited[next.A][next.B][next.C] = true;
                            q.add(next);
                        }
                    }
                }
                if (cur.C < limitC) {
                    if (cur.A + cur.C > limitC) {
                        State next = new State(cur.A, cur.B, cur.C);
                        next.A -= limitC - cur.C;
                        next.C = limitC;
                        if (!visited[next.A][next.B][next.C]) {
                            visited[next.A][next.B][next.C] = true;
                            q.add(next);
                        }
                    } else {
                        State next = new State(cur.A, cur.B, cur.C);
                        next.A = 0;
                        next.C += cur.A;
                        if (!visited[next.A][next.B][next.C]) {
                            visited[next.A][next.B][next.C] = true;
                            q.add(next);
                        }
                    }
                }
            }
            if (cur.B != 0) {
                if (cur.A < limitA) {
                    if (cur.A + cur.B > limitA) {
                        State next = new State(cur.A, cur.B, cur.C);
                        next.B -= limitA - cur.A;
                        next.A = limitA;
                        if (!visited[next.A][next.B][next.C]) {
                            visited[next.A][next.B][next.C] = true;
                            q.add(next);
                        }
                    } else {
                        State next = new State(cur.A, cur.B, cur.C);
                        next.B = 0;
                        next.A += cur.B;
                        if (!visited[next.A][next.B][next.C]) {
                            visited[next.A][next.B][next.C] = true;
                            q.add(next);
                        }
                    }
                }
                if (cur.C < limitC) {
                    if (cur.B + cur.C > limitC) {
                        State next = new State(cur.A, cur.B, cur.C);
                        next.B -= limitC - cur.C;
                        next.C = limitC;
                        if (!visited[next.A][next.B][next.C]) {
                            visited[next.A][next.B][next.C] = true;
                            q.add(next);
                        }
                    } else {
                        State next = new State(cur.A, cur.B, cur.C);
                        next.B = 0;
                        next.C += cur.B;
                        if (!visited[next.A][next.B][next.C]) {
                            visited[next.A][next.B][next.C] = true;
                            q.add(next);
                        }
                    }
                }
            }
            if (cur.C != 0) {
                if (cur.A < limitA) {
                    if (cur.A + cur.C > limitA) {
                        State next = new State(cur.A, cur.B, cur.C);
                        next.C -= limitA - cur.A;
                        next.A = limitA;
                        if (!visited[next.A][next.B][next.C]) {
                            visited[next.A][next.B][next.C] = true;
                            q.add(next);
                        }
                    } else {
                        State next = new State(cur.A, cur.B, cur.C);
                        next.C = 0;
                        next.A += cur.C;
                        if (!visited[next.A][next.B][next.C]) {
                            visited[next.A][next.B][next.C] = true;
                            q.add(next);
                        }
                    }
                }
                if (cur.B < limitB) {
                    if (cur.B + cur.C > limitB) {
                        State next = new State(cur.A, cur.B, cur.C);
                        next.C -= limitB - cur.B;
                        next.B = limitB;
                        if (!visited[next.A][next.B][next.C]) {
                            visited[next.A][next.B][next.C] = true;
                            q.add(next);
                        }
                    } else {
                        State next = new State(cur.A, cur.B, cur.C);
                        next.C = 0;
                        next.B += cur.C;
                        if (!visited[next.A][next.B][next.C]) {
                            visited[next.A][next.B][next.C] = true;
                            q.add(next);
                        }
                    }
                }
            }
        }
        Collections.sort(answer);
        StringBuilder sb = new StringBuilder();
        for (Integer c : answer) {
            sb.append(c + " ");
        }
        System.out.println(sb);
    }
    
    static class State {
        int A;
        int B;
        int C;
        State(){}
        State(int A, int B, int C) {
            this.A = A;
            this.B = B;
            this.C = C;
        } 
    }
}