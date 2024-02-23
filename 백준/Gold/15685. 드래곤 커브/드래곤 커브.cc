#include <iostream>
#include <vector>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

struct line {
    int x;
    int y;
    int d;
    line() {}
    line(int x, int y, int d) : x(x), y(y), d(d) {}
};

int N;
int grid[101][101];
std::vector<line> dragon_curve;

void draw_dragon_curve(int sx, int sy, int d, int g) {
    if (g == 0) {
        dragon_curve.push_back(line(sx, sy, d));
        grid[sy][sx]++;
        return;
    }

    draw_dragon_curve(sx, sy, d, g - 1);
    line last_line = dragon_curve.back();
    int x = last_line.x + dx[last_line.d];
    int y = last_line.y + dy[last_line.d];
    for (int i = dragon_curve.size() - 1; i > -1; i--) {
        grid[y][x]++;
        int nd = (dragon_curve[i].d + 1) % 4;
        int nx = x + dx[nd];
        int ny = y + dy[nd];
        dragon_curve.push_back(line(x, y, nd));
        x = nx;
        y = ny;
    }
}

int main() {
    std::cin >> N;

    int X, Y, D, G;
    for (int i = 0; i < N; i++) {
        std::cin >> X >> Y >> D >> G;
        dragon_curve.clear();
        draw_dragon_curve(X, Y, D, G);
        line last_line = dragon_curve.back();
        int x = last_line.x + dx[last_line.d];
        int y = last_line.y + dy[last_line.d];
        grid[y][x]++;
    }

    int answer = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (grid[i][j] > 0 && grid[i + 1][j] > 0 && grid[i + 1][j + 1] > 0 && grid[i][j + 1] > 0) {
                answer++;
            }
        }
    }
    std::cout << answer << "\n";
    return 0;
}
