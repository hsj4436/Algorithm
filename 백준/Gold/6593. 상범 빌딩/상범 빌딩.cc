#include <iostream>
#include <queue>
#include <tuple>

int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int L, R, C;
int sX, sY, sZ;
int eX, eY, eZ;
char building[31][31][31]; // {L, R, C}
int time[31][31][31];

int main() {
    while (std::cin >> L >> R >> C) {
        if (L == 0 && R == 0 && C == 0) {
            break;
        }

        std::string c;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                std::cin >> c;
                for (int k = 0; k < C; k++) {
                    if (c[k] == 'S') {
                        sX = j, sY = k, sZ = i;
                        c[k] = '.';
                    }
                    building[i][j][k] = c[k];
                    if (c[k] == 'E') {
                        eX = j, eY = k, eZ = i;
                    }
                }
            }
        }

        int MAX = L * R * C + 1;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    time[i][j][k] = MAX;
                }
            }
        }
        std::queue<std::pair<std::tuple<int, int, int>, int>> q;
        q.push({std::tuple(sX, sY, sZ), 0});
        time[sZ][sX][sY] = 0;

        while (!q.empty()) {
            int cX = std::get<0>(q.front().first);
            int cY = std::get<1>(q.front().first);
            int cZ = std::get<2>(q.front().first);
            int t = q.front().second;
            q.pop();

            if (building[cZ][cX][cY] == 'E' || t > MAX || t > time[cZ][cX][cY]) {
                continue;
            }

            for (int i = 0; i < 6; i++) {
                int nX = cX + dx[i];
                int nY = cY + dy[i];
                int nZ = cZ + dz[i];

                if (nX < 0 || nX > R - 1 || nY < 0 || nY > C - 1 || nZ < 0 || nZ > L - 1) {
                    continue;
                }

                if (t + 1 >= time[nZ][nX][nY] || building[nZ][nX][nY] == '#') {
                    continue;
                }

                time[nZ][nX][nY] = t + 1;
                q.push({std::tuple(nX, nY, nZ), t + 1});
            }
        }

        if (time[eZ][eX][eY] != MAX) {
            std::cout << "Escaped in " + std::to_string(time[eZ][eX][eY]) + " minute(s).\n";
        } else {
            std::cout << "Trapped!\n";
        }
    }
    return 0;
}
