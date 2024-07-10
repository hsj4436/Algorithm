import java.io.*;
import java.util.*;

public class Main {

    static final int H = 5, W = 9;
    static final int[] dx = new int[]{-1, 0, 1, 0};
    static final int[] dy = new int[]{0, -1, 0, 1};

    static int N;
    static char[][] board;
    static int initialPin, lastPin, answer;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        while (N-- != 0) {
            board = new char[H][W];
            initialPin = 0;
            lastPin = 8;
            answer = 300;
            for (int i = 0; i < H; i++) {
                board[i] = br.readLine().toCharArray();
                for (int j = 0; j < W; j++) {
                    if (board[i][j] == 'o') {
                        initialPin++;
                    }
                }
            }

            br.readLine();

            backTrack(0, 0);
            System.out.println(lastPin + " " + answer);
        }
    }

    static void backTrack(int erased, int moved) {
        if (initialPin - erased < lastPin) {
            lastPin = initialPin - erased;
            answer = moved;
            if (erased + 1 == initialPin) {
                return;
            }
        }
        if (initialPin - erased == lastPin) {
            if (moved < answer) {
                answer = moved;
            }
            if (erased + 1 == initialPin) {
                return;
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (board[i][j] == 'o') {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx < 0 || nx > H - 1 || ny < 0 || ny > W - 1) {
                            continue;
                        }
                        if (board[nx][ny] == 'o') {
                            int nnx = nx + dx[k];
                            int nny = ny + dy[k];
                            if (nnx < 0 || nnx > H - 1 || nny < 0 || nny > W - 1) {
                                continue;
                            }
                            if (board[nnx][nny] == '.') {
                                board[nnx][nny] = 'o';
                                board[nx][ny] = '.';
                                board[i][j] = '.';
                                backTrack(erased + 1, moved + 1);
                                board[nnx][nny] = '.';
                                board[nx][ny] = 'o';
                                board[i][j] = 'o';
                            }
                        }
                    }
                }
            }
        }
    }
}