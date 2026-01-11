import java.util.*;

class Solution {
    
    private static int[] dx = new int[]{-1, 0, 1, 0};
    private static int[] dy = new int[]{0, -1, 0, 1};
    private int answer = 0;
    private int N;
    private boolean[] used;
    private List<int[][]> boards = new ArrayList<>();
    private List<int[][]> tables = new ArrayList<>();
    
    private int[][] makeBlock(int[][] table, int x, int y, int blocked) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        int minX = x, minY = y;
        int maxX = x, maxY = y;
        List<int[]> points = new ArrayList<>();
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            table[cur[0]][cur[1]] = -1;
            points.add(cur);
            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                
                if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
                    continue;
                }
                if (table[nx][ny] == blocked || table[nx][ny] == -1) {
                    continue;
                }
                minX = Math.min(minX, nx);
                minY = Math.min(minY, ny);
                maxX = Math.max(maxX, nx);
                maxY = Math.max(maxY, ny);
                q.offer(new int[]{nx, ny});
            }
        }
        int[][] block = new int[maxX - minX + 1][maxY - minY + 1];
        for (int[] i : points) {
            block[i[0] - minX][i[1] - minY] = 1;
        }
        
        return block;
    }
    
    private boolean isUsable(int boardsIndex, int tablesIndex) {
        int[][] board = boards.get(boardsIndex);
        int[][] table = tables.get(tablesIndex);
        int bHeight = board.length, bWidth = board[0].length;
        int tHeight = table.length, tWidth = table[0].length;
        boolean isFitted = true;
        
        // 0, 180
        if (bHeight == tHeight && bWidth == tWidth) {
            for (int i = 0; i < bHeight; i++) {
                for (int j = 0; j < bWidth; j++) {
                    if (board[i][j] != table[i][j]) {
                        isFitted = false;
                        break;
                    }
                }
                if (!isFitted) {
                    break;
                }
            }
            if (isFitted) {
                return true;
            }
            isFitted = true;
            for (int i = 0; i < bHeight; i++) {
                for (int j = 0; j < bWidth; j++) {
                    if (board[i][j] != table[tHeight - 1 - i][tWidth - 1 - j]) {
                        isFitted = false;
                        break;
                    }
                }
                if (!isFitted) {
                    break;
                }
            }
            if (isFitted) {
                return true;
            }
        }
        isFitted = true;
        // 90, 270
        if (bHeight == tWidth && bWidth == tHeight) {
            for (int i = 0; i < bHeight; i++) {
                for (int j = 0; j < bWidth; j++) {
                    if (board[i][j] != table[tHeight - 1 - j][i]) {
                        isFitted = false;
                        break;
                    }
                }
                if (!isFitted) {
                    break;
                }
            }
            if (isFitted) {
                return true;
            }
            isFitted = true;
            for (int i = 0; i < bHeight; i++) {
                for (int j = 0; j < bWidth; j++) {
                    if (board[i][j] != table[j][tWidth - 1 - i]) {
                        isFitted = false;
                        break;
                    }
                }
                if (!isFitted) {
                    break;
                }
            }
            if (isFitted) {
                return true;
            }
        }
        
        return false;
    }

    private void checkFilled() {
        int count = 0;
        for (int i = 0; i < tables.size(); i++) {
            if (!used[i]) {
                continue;
            }
            for (int j = 0; j < tables.get(i).length; j++) {
                for (int k = 0; k < tables.get(i)[j].length; k++) {
                    if (tables.get(i)[j][k] == 1) {
                        count++;
                    }
                }
            }
        }
        answer = Math.max(answer, count);
    }
    
    private void sol() {
        for (int i = 0; i < boards.size(); i++) {
            for (int j = 0; j < tables.size(); j++) {
                if (used[j]) {
                    continue;
                }
                if (isUsable(i, j)) {
                    used[j] = true;
                    break;
                }
            }
        }
        checkFilled();
    }
    
    public int solution(int[][] game_board, int[][] table) {
        N = game_board.length;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (table[i][j] == 1) {
                    tables.add(makeBlock(table, i, j, 0));
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (game_board[i][j] == 0) {
                    boards.add(makeBlock(game_board, i, j, 1));
                }
            }
        }
        used = new boolean[tables.size()];
        
        sol();
        
        return answer;
    }
}