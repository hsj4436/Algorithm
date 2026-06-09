import java.util.*;

class Solution {
    
    private static final int[] dx = new int[]{-1, 0, 1, 0};
    private static final int[] dy = new int[]{0, -1, 0, 1};
    
    private static int N;
    private static int M;
    
    public int solution(String[] storage, String[] requests) {
        N = storage.length;
        M = storage[0].length();
        int answer = N * M;
        char[][] st = new char[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                st[i][j] = storage[i].charAt(j);
            }
        }
        
        List<int[]> popped;
        for (int r = 0; r < requests.length; r++) {
            popped = new ArrayList<>();
            if (requests[r].length() == 1) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        if (String.valueOf(st[i][j]).equals(requests[r])) {
                            boolean[][] visited = new boolean[N][M];
                            visited[i][j] = true;
                            if (dfs(i, j, st, visited)) {
                                popped.add(new int[]{i, j});
                            }
                        }            
                    }
                }
            } else {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        if (st[i][j] == requests[r].charAt(0)) {
                            popped.add(new int[]{i, j});
                        }         
                    }
                }
            }
            
            for (int[] p : popped) {
                st[p[0]][p[1]] = '_';
            }
            
            answer -= popped.size();
        }
        
        return answer;
    }
    
    private static boolean dfs(int x, int y, char[][] st, boolean[][] visited) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
                return true;
            }
            if (visited[nx][ny]) {
                continue;
            }
            if (st[nx][ny] == '_') {
                visited[nx][ny] = true;
                if (dfs(nx, ny, st, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
}