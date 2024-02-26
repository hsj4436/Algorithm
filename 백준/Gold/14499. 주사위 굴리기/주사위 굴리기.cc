#include <iostream>

#define PII std::pair<int, int>

int N, M, K;
int map[21][21];
PII dice;
int dice_side[6] = {0, 0, 0, 0, 0}; // west, north, TOP, east, south, BOTTOM

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void move_dice(int command) {
    int cur_west = dice_side[0];
    int cur_north = dice_side[1];
    int cur_TOP = dice_side[2];
    int cur_east = dice_side[3];
    int cur_south = dice_side[4];
    int cur_BOTTOM = dice_side[5];
    if (command == 0) {
        dice_side[0] = cur_BOTTOM;
        dice_side[1] = cur_north;
        dice_side[2] = cur_west;
        dice_side[3] = cur_TOP;
        dice_side[4] = cur_south;
        dice_side[5] = cur_east;
    } else if (command == 1) {
        dice_side[0] = cur_TOP;
        dice_side[1] = cur_north;
        dice_side[2] = cur_east;
        dice_side[3] = cur_BOTTOM;
        dice_side[4] = cur_south;
        dice_side[5] = cur_west;
    } else if (command == 2) {
        dice_side[0] = cur_west;
        dice_side[1] = cur_TOP;
        dice_side[2] = cur_south;
        dice_side[3] = cur_east;
        dice_side[4] = cur_BOTTOM;
        dice_side[5] = cur_north;
    } else if (command == 3) {
        dice_side[0] = cur_west;
        dice_side[1] = cur_BOTTOM;
        dice_side[2] = cur_north;
        dice_side[3] = cur_east;
        dice_side[4] = cur_TOP;
        dice_side[5] = cur_south;
    }
}

int main() {
    std::cin >> N >> M;
    std::cin >> dice.first >> dice.second;
    std::cin >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
        }
    }

    int command;
    for (int i = 0; i < K; i++) {
        std::cin >> command;
        command--;
        int nx = dice.first + dx[command];
        int ny = dice.second + dy[command];

        if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
            continue;
        }
        dice = {nx, ny};
        move_dice(command);
        if (map[nx][ny] != 0) {
            dice_side[5] = map[nx][ny];
            map[nx][ny] = 0;
        } else {
            map[nx][ny] = dice_side[5];
        }
        std::cout << dice_side[2] << "\n";
    }

    return 0;
}
