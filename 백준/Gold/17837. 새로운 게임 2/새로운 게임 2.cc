#include <iostream>
#include <vector>

struct object {
    int x;
    int y;
    int d;
    object(){}
    object(int x, int y, int d) : x(x), y(y), d(d) {}
};

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int N, K;
std::pair<int, std::vector<int>> board[13][13];
object objects[11];

int main() {
    std::cin >> N >> K;

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            std::cin >> board[i][j].first;
        }
    }

    int X, Y, D;
    for (int i = 0; i < K; i++) {
        std::cin >> X >> Y >> D;
        objects[i] = object(X, Y, D);
        board[X][Y].second.push_back(i);
    }

    for (int i = 1; i < 1001; i++) {
        for (int j = 0; j < K; j++) {
            int nx = objects[j].x + dx[objects[j].d];
            int ny = objects[j].y + dy[objects[j].d];

            if ((nx < 1 || nx > N || ny < 1 || ny > N) || board[nx][ny].first == 2) {
                if (objects[j].d == 1) {
                    objects[j].d = 2;
                } else if (objects[j].d == 2) {
                    objects[j].d = 1;
                } else if (objects[j].d == 3) {
                    objects[j].d = 4;
                } else {
                    objects[j].d = 3;
                }
                nx = objects[j].x + dx[objects[j].d];
                ny = objects[j].y + dy[objects[j].d];
                if ((nx < 1 || nx > N || ny < 1 || ny > N) || board[nx][ny].first == 2) {
                    continue;
                } else if (board[nx][ny].first == 0) {
                    std::vector<int> stk;
                    while (board[objects[j].x][objects[j].y].second.back() != j) {
                        stk.push_back(board[objects[j].x][objects[j].y].second.back());
                        board[objects[j].x][objects[j].y].second.pop_back();
                    }
                    stk.push_back(board[objects[j].x][objects[j].y].second.back());
                    board[objects[j].x][objects[j].y].second.pop_back();

                    while (!stk.empty()) {
                        int index = stk.back();
                        stk.pop_back();
                        board[nx][ny].second.push_back(index);
                        objects[index].x = nx;
                        objects[index].y = ny;
                    }
                    if (board[nx][ny].second.size() >= 4) {
                        std::cout << i << "\n";
                        return 0;
                    }
                } else if (board[nx][ny].first == 1) {
                    std::vector<int> stk;
                    while (board[objects[j].x][objects[j].y].second.back() != j) {
                        stk.push_back(board[objects[j].x][objects[j].y].second.back());
                        board[objects[j].x][objects[j].y].second.pop_back();
                    }
                    stk.push_back(board[objects[j].x][objects[j].y].second.back());
                    board[objects[j].x][objects[j].y].second.pop_back();

                    for (int index = 0; index < stk.size(); index++) {
                        objects[stk[index]].x = nx;
                        objects[stk[index]].y = ny;
                        board[nx][ny].second.push_back(stk[index]);
                    }

                    if (board[nx][ny].second.size() >= 4) {
                        std::cout << i << "\n";
                        return 0;
                    }
                }
            } else if (board[nx][ny].first == 0) {
                std::vector<int> stk;
                while (board[objects[j].x][objects[j].y].second.back() != j) {
                    stk.push_back(board[objects[j].x][objects[j].y].second.back());
                    board[objects[j].x][objects[j].y].second.pop_back();
                }
                stk.push_back(board[objects[j].x][objects[j].y].second.back());
                board[objects[j].x][objects[j].y].second.pop_back();

                while (!stk.empty()) {
                    int index = stk.back();
                    stk.pop_back();
                    board[nx][ny].second.push_back(index);
                    objects[index].x = nx;
                    objects[index].y = ny;
                }
                if (board[nx][ny].second.size() >= 4) {
                    std::cout << i << "\n";
                    return 0;
                }
            } else if (board[nx][ny].first == 1) {
                std::vector<int> stk;
                while (board[objects[j].x][objects[j].y].second.back() != j) {
                    stk.push_back(board[objects[j].x][objects[j].y].second.back());
                    board[objects[j].x][objects[j].y].second.pop_back();
                }
                stk.push_back(board[objects[j].x][objects[j].y].second.back());
                board[objects[j].x][objects[j].y].second.pop_back();

                for (int index = 0; index < stk.size(); index++) {
                    objects[stk[index]].x = nx;
                    objects[stk[index]].y = ny;
                    board[nx][ny].second.push_back(stk[index]);
                }

                if (board[nx][ny].second.size() >= 4) {
                    std::cout << i << "\n";
                    return 0;
                }
            }
        }
    }

    std::cout << "-1\n";

    return 0;
}
