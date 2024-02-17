#include <iostream>
#include <vector>

#define PII std::pair<int, int>

int dx[4] = {0, 1, 0, -1}; // R, D, L, U
int dy[4] = {1, 0, -1, 0};

int N, K, L;
int X;
char C;
int board[101][101];
std::vector<PII> command;
int direction = 0;
int command_index = 0;
PII head;
PII tail;
int t = 1;

bool move() {
    int nx = head.first + dx[direction];
    int ny = head.second + dy[direction];

    if (nx < 1 || nx > N || ny < 1 || ny > N) {
        return false;
    }

    if (board[nx][ny] > 0) {
        return false;
    }

    if (board[nx][ny] == -1) {
        // Apple in next cell
        board[nx][ny] = board[head.first][head.second] + 1;
    } else {
        // normal cell
        board[nx][ny] = board[head.first][head.second] + 1;
        for (int i = 0; i < 4; i++) {
            int tnx = tail.first + dx[i];
            int tny = tail.second + dy[i];

            if (tnx < 1 || tnx > N || tny < 1 || tny > N) {
                continue;
            }

            if (board[tnx][tny] == board[tail.first][tail.second] + 1) {
                board[tail.first][tail.second] = 0;
                tail = {tnx, tny};
                break;
            }
        }
    }
    head = {nx, ny};

    return true;
}

int main() {
    std::cin >> N >> K;

    board[1][1] = 1;
    head = {1, 1};
    tail = {1, 1};

    int row, col;
    for (int i = 0; i < K; i++) {
        std::cin >> row >> col;
        board[row][col] = -1;
    }

    std::cin >> L;

    for (int i = 0; i < L; i++) {
        std::cin >> X >> C;
        if (C == 'L') {
            command.push_back({X, -1});
        } else {
            command.push_back({X, 1});
        }
    }

    while (move()) {
        if (command_index != command.size()) {
            if (t == command[command_index].first) {
                direction = (direction + command[command_index].second + 4) % 4;
                command_index++;
            }
        }
        t++;
    }

    std::cout << t << "\n";

    return 0;
}
