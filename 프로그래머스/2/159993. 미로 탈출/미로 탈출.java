import java.util.*;

class Solution {
    
    private static final int INF = 987654321;
    private static int[] dx = new int[]{-1, 0, 1, 0};
    private static int[] dy = new int[]{0, -1, 0, 1};
    
    public int solution(String[] maps) {
        int sx = 0, sy = 0;
        int lx = 0, ly = 0;
        int ex = 0, ey = 0;
        char[][] map = new char[maps.length][maps[0].length()];
        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[i].length(); j++) {
                map[i][j] = maps[i].charAt(j);
                if (map[i][j] == 'S') {
                    sx = i;
                    sy = j;
                    map[i][j] = 'O';
                }
                if (map[i][j] == 'E') {
                    ex = i;
                    ey = j;
                    map[i][j] = 'O';
                }
                if (map[i][j] == 'L') {
                    lx = i;
                    ly = j;
                    map[i][j] = 'O';
                }
            }
        }
        
        int toLever = goTo(sx, sy, lx, ly, map);
        if (toLever == -1) {
            return -1;
        }
        int toExit = goTo(lx, ly, ex, ey, map);
        if (toExit == -1) {
            return -1;
        }
        
        return toLever + toExit;
    }
    
    private static int goTo(int x, int y, int tx, int ty, char[][] map) {
        Queue<int[]> q = new LinkedList<>();
        int[][] visited = new int[map.length][map[0].length];
        for (int i = 0; i < visited.length; i++) {
            Arrays.fill(visited[i], INF);
        }
        visited[x][y] = 0;
        q.add(new int[]{x, y, 0});
        
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            
            if (cur[0] == tx && cur[1] == ty) {
                continue;
            }
            
            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                if (nx < 0 || nx > map.length - 1 || ny < 0 || ny > map[0].length - 1) {
                    continue;
                }
                if (map[nx][ny] == 'X' || cur[2] + 1 >= visited[nx][ny]) {
                    continue;
                }
                visited[nx][ny] = cur[2] + 1;
                q.add(new int[]{nx, ny, cur[2] + 1});
            }
        }
        
        if (visited[tx][ty] == INF) {
            return -1;
        } else {
            return visited[tx][ty];
        }
    }
}