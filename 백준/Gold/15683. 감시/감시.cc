#include <iostream>
#include <vector>

int N, M;
int room[9][9];
std::vector<std::pair<int, std::pair<int, int>>> cameras;
int answer = 64;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

std::pair<int, int> visible(int direction, int nx, int ny) {
    while (true) {
        if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
            break;
        }
        if (room[nx][ny] == 6) {
            break;
        }
        if (room[nx][ny] <= 0) {
            room[nx][ny]--;
        }
        nx += dx[direction];
        ny += dy[direction];
    }

    return {nx, ny};
}

void unvisible(int c_index, int direction, int nx, int ny) {
    nx -= dx[direction];
    ny -= dy[direction];
    while (true) {
        if (nx == cameras[c_index].second.first && ny == cameras[c_index].second.second) {
            break;
        }
        if (room[nx][ny] < 0) {
            room[nx][ny]++;
        }
        nx -= dx[direction];
        ny -= dy[direction];
    }
}

void sol(int c_index) {
    if (c_index == cameras.size()) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (room[i][j] == 0) {
                    cnt++;
                }
            }
        }
        answer = std::min(answer, cnt);
        return;
    }

    if (cameras[c_index].first == 1) {
        for (int i = 0; i < 4; i++) {
            int nx = cameras[c_index].second.first + dx[i];
            int ny = cameras[c_index].second.second + dy[i];
            auto p = visible(i, nx, ny);
            sol(c_index + 1);
            unvisible(c_index, i, p.first, p.second);
        }
    } else if (cameras[c_index].first == 2) {
        for (int i = 0; i < 2; i++) {
            int x1 = cameras[c_index].second.first + dx[i];
            int y1 = cameras[c_index].second.second + dy[i];
            int x2 = cameras[c_index].second.first + dx[(i + 2) % 4];
            int y2 = cameras[c_index].second.second + dy[(i + 2) % 4];
            auto p1 = visible(i, x1, y1);
            auto p2 = visible((i + 2) % 4, x2, y2);
            sol(c_index + 1);
            unvisible(c_index, i, p1.first, p1.second);
            unvisible(c_index, (i + 2) % 4, p2.first, p2.second);
        }
    } else if (cameras[c_index].first == 3) {
        for (int i = 0; i < 4; i++) {
            int x1 = cameras[c_index].second.first + dx[i];
            int y1 = cameras[c_index].second.second + dy[i];
            int x2 = cameras[c_index].second.first + dx[(i + 1) % 4];
            int y2 = cameras[c_index].second.second + dy[(i + 1) % 4];
            auto p1 = visible(i, x1, y1);
            auto p2 = visible((i + 1) % 4, x2, y2);
            sol(c_index + 1);
            unvisible(c_index, i, p1.first, p1.second);
            unvisible(c_index, (i + 1) % 4, p2.first, p2.second);
        }

    } else if (cameras[c_index].first == 4) {
        for (int i = 0; i < 4; i++) {
            int x1 = cameras[c_index].second.first + dx[i];
            int y1 = cameras[c_index].second.second + dy[i];
            int x2 = cameras[c_index].second.first + dx[(i + 1) % 4];
            int y2 = cameras[c_index].second.second + dy[(i + 1) % 4];
            int x3 = cameras[c_index].second.first + dx[(i + 2) % 4];
            int y3 = cameras[c_index].second.second + dy[(i + 2) % 4];
            auto p1 = visible(i, x1, y1);
            auto p2 = visible((i + 1) % 4, x2, y2);
            auto p3 = visible((i + 2) % 4, x3, y3);
            sol(c_index + 1);
            unvisible(c_index, i, p1.first, p1.second);
            unvisible(c_index, (i + 1) % 4, p2.first, p2.second);
            unvisible(c_index, (i + 2) % 4, p3.first, p3.second);
        }
    } else {
        int x1 = cameras[c_index].second.first + dx[0];
        int y1 = cameras[c_index].second.second + dy[0];
        int x2 = cameras[c_index].second.first + dx[1];
        int y2 = cameras[c_index].second.second + dy[1];
        int x3 = cameras[c_index].second.first + dx[2];
        int y3 = cameras[c_index].second.second + dy[2];
        int x4 = cameras[c_index].second.first + dx[3];
        int y4 = cameras[c_index].second.second + dy[3];
        auto p1 = visible(0, x1, y1);
        auto p2 = visible(1, x2, y2);
        auto p3 = visible(2, x3, y3);
        auto p4 = visible(3, x4, y4);
        sol(c_index + 1);
        unvisible(c_index, 0, p1.first, p1.second);
        unvisible(c_index, 1, p2.first, p2.second);
        unvisible(c_index, 2, p3.first, p3.second);
        unvisible(c_index, 3, p4.first, p4.second);
    }
}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> room[i][j];
            if (room[i][j] >= 1 && room[i][j] <= 5) {
                cameras.push_back({room[i][j], {i, j}});
            }
        }
    }

    sol(0);

    std::cout << answer << "\n";

    return 0;
}
