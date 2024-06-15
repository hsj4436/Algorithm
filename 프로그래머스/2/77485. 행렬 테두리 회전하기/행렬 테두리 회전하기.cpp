#include <string>
#include <vector>

using namespace std;

int matrix[101][101];

void init(int r, int c) {
    int number = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            matrix[i][j] = number;
            number++;
        }
    }
}

int executeQuery(int x1, int y1, int x2, int y2) {
    int direction = 0;
    int temp = matrix[x1][y1];
    int minNumber = temp;
    int curX = x1, curY = y1 + 1;
    while (direction != 4) {
        if (direction == 0) {
            swap(matrix[curX][curY], temp);
            if (curY == y2) {
                direction++;
                curX++;
            } else {
                curY++;
            }
        } else if (direction == 1) {
            swap(matrix[curX][curY], temp);
            if (curX == x2) {
                direction++;
                curY--;
            } else {
                curX++;
            }
        } else if (direction == 2) {
            swap(matrix[curX][curY], temp);
            if (curY == y1) {
                direction++;
                curX--;
            } else {
                curY--;
            }
        } else {
            swap(matrix[curX][curY], temp);
            if (curX == x1) {
                direction++;
            } else {
                curX--;
            }
        }
        minNumber = min(minNumber, temp);
    }
    return minNumber;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    init(rows, columns);
    for (vector<int> query : queries) {
        int x1 = query[0] - 1, y1 = query[1] - 1;
        int x2 = query[2] - 1, y2 = query[3] - 1;
        answer.push_back(executeQuery(x1, y1, x2, y2));
    }
    return answer;
}