#include <iostream>
#include <queue>
#include <map>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
string ordered = "123456780";
map<string, bool> m;

int main() {
    string origin;
    int n;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> n;
            origin.push_back(n + '0');
        }
    }

    queue<pair<string, int>> q;
    q.push({origin, 0});
    m[origin] = true;

    while (!q.empty()) {
        string cur = q.front().first;
        int moved = q.front().second;
        q.pop();

        if (cur == ordered) {
            std::cout << moved << "\n";
            return 0;
        }

        int zeroIndex = 0;
        for (int i = 0; i < cur.size(); i++) {
            if (cur[i] == '0') {
                zeroIndex = i;
                break;
            }
        }
        int zx = zeroIndex / 3;
        int zy = zeroIndex % 3;
        for (int i = 0; i < 4; i++) {
            int nx = zx + dx[i];
            int ny = zy + dy[i];
            if (nx < 0 || nx > 2 || ny < 0 || ny > 2) {
                continue;
            }
            std::swap(cur[zeroIndex], cur[nx * 3 + ny]);
            if (!m[cur]) {
                m[cur] = true;
                q.push({cur, moved + 1});
            }
            std::swap(cur[zeroIndex], cur[nx * 3 + ny]);
        }
    }

    std::cout << "-1\n";

    return 0;
}
