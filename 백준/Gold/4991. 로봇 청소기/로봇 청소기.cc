#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int W, H;
char room[20][20];
bool visited[20][20][1 << 10];
int toClean = 0;

void init() {
    fill_n(&room[0][0], sizeof(room), 'x');
    fill_n(&visited[0][0][0], sizeof(visited), false);
    toClean = 0;
}

int main() {
    while (true) {
        cin >> W >> H;
        if (W == 0 && H == 0) {
            break;
        }

        init();

        int X = 0, Y = 0;
        string row;
        for (int i = 0; i < H; i++) {
            cin >> row;
            for (int j = 0; j < W; j++) {
                room[i][j] = row[j];
                if (row[j] == 'o') {
                    X = i, Y = j;
                    room[i][j] = '.';
                } else if (row[j] == '*') {
                    room[i][j] = (toClean + '0');
                    toClean++;
                }
            }
        }

        int answer = -1;
        // {{X, Y}, {state, moved}}
        queue<pair<pair<int, int>, pair<int, int>>> q;
        q.push({{X, Y}, {0, 0}});

        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int state = q.front().second.first;
            int moved = q.front().second.second;
            q.pop();

            if (state == (1 << toClean) - 1) {
                answer = moved;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nd = moved + 1;
                int ns = state;
                if (nx < 0 || nx > H - 1 || ny < 0 || ny > W - 1) {
                    continue;
                }
                if (room[nx][ny] == 'x') {
                    continue;
                }
                if ('0' <= room[nx][ny] && room[nx][ny] <= '9') {
                    int cellNumber = room[nx][ny] - '0';
                    ns |= (1 << cellNumber);
                }
                if (visited[nx][ny][state]) {
                    continue;
                }
                visited[nx][ny][state] = true;
                q.push({{nx, ny}, {ns, nd}});
            }
        }
        cout << answer << "\n";
    }
    return 0;
}
