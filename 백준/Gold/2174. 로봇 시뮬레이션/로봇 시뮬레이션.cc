#include <iostream>
#include <map>

int A, B;
int N, M;
int ground[101][101];

int dx[4] = {0, 1, 0, -1};  // NESW
int dy[4] = {1, 0, -1, 0};

struct robot {
    int x;
    int y;
    int d; // direction
    robot() {

    }
    robot(int x, int y, int d) {
        this->x = x;
        this->y = y;
        this->d = d;
    }
};

int main() {
    std::cin >> A >> B;
    std::cin >> N >> M;

    std::map<int, robot> robots;

    for (int i = 0; i < N; i++) {
        int x, y;
        char d;
        std::cin >> x >> y >> d;
        switch (d) {
            case 'E':
                robots[i + 1] = robot(x, y, 1);
                ground[B - (y - 1)][x] = i + 1;
                break;
            case 'W':
                robots[i + 1] = robot(x, y, 3);
                ground[B - (y - 1)][x] = i + 1;
                break;
            case 'N':
                robots[i + 1] = robot(x, y, 0);
                ground[B - (y - 1)][x] = i + 1;
                break;
            case 'S':
                robots[i + 1] = robot(x, y, 2);
                ground[B - (y - 1)][x] = i + 1;
                break;
            default:
                break;
        }
    }

//    for (int i = 1; i < B + 1; i++) {
//        for (int j = 1; j < A + 1; j++) {
//            std::cout << ground[i][j] << " ";
//        }
//        std::cout << "\n";
//    }
//    std::cout << "\n";

    for (int i = 0; i < M; i++) {
        int robot_number;
        char command;
        int count;
        std::cin >> robot_number >> command >> count;

        for (int j = 0; j < count; j++) {
            robot r = robots[robot_number];
            switch (command) {
                case 'L':
                    robots[robot_number] = robot(r.x, r.y, r.d - 1 < 0 ? (r.d - 1) % 4 + 4 : (r.d - 1) % 4);
                    break;
                case 'R':
                    robots[robot_number] = robot(r.x, r.y, (r.d + 1) % 4);
                    break;
                case 'F': {
                    int nx = r.x + dx[r.d];
                    int ny = r.y + dy[r.d];
                    if (B - (ny - 1) < 1 || B - (ny - 1) > B || nx < 1 || nx > A) {
                        std::cout << "Robot " << robot_number << " crashes into the wall\n";
                        return 0;
                    }
                    if (ground[B- (ny - 1)][nx] > 0) {
                        std::cout << "Robot " << robot_number << " crashes into robot " << ground[B - (ny - 1)][nx] << "\n";
                        return 0;
                    }

                    ground[B - (r.y - 1)][r.x] = 0;
                    ground[B - (ny - 1)][nx] = robot_number;
                    robots[robot_number] = robot(nx, ny, r.d);
                    break;
                }
                default:
                    break;
            }
        }
    }
    
    std::cout << "OK\n";

    return 0;
}
