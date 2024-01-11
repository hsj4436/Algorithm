#include <iostream>

int N;
int paper[101][101];
int row_sum[101][101];
int col_sum[101][101];
int row_size[101][101];
int col_size[101][101];

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> y >> x;
        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                paper[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (paper[i][j] == 1) {
                if (j == 0) {
                    row_sum[i][j] = 1;
                } else {
                    row_sum[i][j] = row_sum[i][j - 1] + 1;
                }
                if (i == 0) {
                    col_sum[i][j] = 1;
                } else {
                    col_sum[i][j] = col_sum[i - 1][j] + 1;
                }
            }
        }
    }


    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (row_sum[i][j] != 0) {
                int up = i;
                int bottom = i;
                while (row_sum[bottom][j] >= row_sum[i][j]) {
                    bottom++;
                }
                while (row_sum[up][j] >= row_sum[i][j]) {
                    up--;
                }
                row_size[i][j] = row_sum[i][j] * (bottom - up - 1);
            }
            if (col_sum[i][j] != 0) {
                int left = j;
                int right = j;
                while (col_sum[i][right] >= col_sum[i][j]) {
                    right++;
                }
                while (col_sum[i][left] >= col_sum[i][j]) {
                    left--;
                }
                col_size[i][j] = col_sum[i][j] * (right - left - 1);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            answer = std::max(answer, std::max(row_size[i][j], col_size[i][j]));
        }
    }

    std::cout << answer << "\n";

    return 0;
}
