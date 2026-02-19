import java.util.*;

class Solution {
    
    private int N;
    private int M;
    private int[][] degree;
    
    public int solution(int[][] board, int[][] skill) {
        int answer = 0;
        N = board.length;
        M = board[0].length;
        degree = new int[N][M];
        
        int base = 0;
        int r1 = 0, c1 = 0;
        int r2 = 0, c2 = 0;
        int d = 0;
        for (int i = 0; i < skill.length; i++) {
            base = skill[i][0] == 1 ? -1 : 1;
            r1 = skill[i][1];
            c1 = skill[i][2];
            r2 = Math.min(skill[i][3] + 1, N);
            c2 = Math.min(skill[i][4] + 1, M);
            d = base * skill[i][5];
            degree[r1][c1] += d;
            if (r2 < N) {
                degree[r2][c1] += -1 * d;
            }
            if (c2 < M) {
                degree[r1][c2] += -1 * d;
            }
            if (r2 < N && c2 < M) {
                degree[r2][c2] += d;
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < M; j++) {
                degree[i][j] += degree[i][j - 1];
            }
        }
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M; j++) {
                degree[i][j] += degree[i - 1][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] + degree[i][j] > 0) {
                    answer++;
                }
            }
        }
        
        return answer;
    }
}