#include <iostream>
#include <vector>

int N;
std::vector<std::pair<int, int>> whites;
std::vector<std::pair<int, int>> blacks;
bool visited[11][11];
int answer[2];
std::pair<int, int> dxdy[2] = {{-1, -1}, {-1, 1}};

bool check_possible(int x, int y) {
    for (int i = 0; i < 2; i++) {
        int nx = x;
        int ny = y;
        while (true) {
            nx += dxdy[i].first;
            ny += dxdy[i].second;
            if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
                break;
            }
            if (visited[nx][ny]) {
                return false;
            }
        }
    }
    return true;
}

void back_track(int index, int cnt, int color) {
    if (cnt > answer[color]) {
        answer[color] = cnt;
    }

    if (color == 0) {
        if (index == whites.size()) {
            return;
        }
        if (cnt + (whites.size() - index) < answer[color]) {
            return;
        }
    } else {
        if (index == blacks.size()) {
            return;
        }
        if (cnt + (blacks.size() - index) < answer[color]) {
            return;
        }
    }

    if (color == 0) {
        for (int i = index; i < whites.size(); i++) {
            int x = whites[i].first;
            int y = whites[i].second;
            if (check_possible(x, y)) {
                visited[x][y] = true;
                back_track(i + 1, cnt + 1, color);
                visited[x][y] = false;
            }
        }
    } else {
        for (int i = index; i < blacks.size(); i++) {
            int x = blacks[i].first;
            int y = blacks[i].second;
            if (check_possible(x, y)) {
                visited[x][y] = true;
                back_track(i + 1, cnt + 1, color);
                visited[x][y] = false;
            }
        }
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cell;
            std::cin >> cell;
            if (cell == 1) {
                if ((i + j) % 2 == 0) {
                    whites.push_back({i, j});
                } else {
                    blacks.push_back({i, j});
                }
            }
        }
    }

    back_track(0, 0, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
    back_track(0, 0, 1);

    std::cout << answer[0] + answer[1] << "\n";
    return 0;
}
