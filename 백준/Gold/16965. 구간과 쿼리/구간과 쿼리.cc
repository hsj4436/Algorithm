#include <iostream>

int N;
std::pair<int, int> sector[101];
bool dist[101][101];

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        dist[i][i] = true;
        sector[i] = {-2000000001, -2000000001};
    }

    int q;
    int x, y;
    int index = 1;
    for (int i = 1; i < N + 1; i++) {
        std::cin >> q >> x >> y;

        if (q == 1) {
            sector[index] = {x, y};
            index++;
            for (int c = 1; c < N + 1; c++) {
                for (int a = 1; a < N + 1; a++) {
                    if (a == c) {
                        continue;
                    }
                    for (int b = 1; b < N + 1; b++) {
                        if (a == b || b == c) {
                            continue;
                        }
                        int x1 = sector[a].first, y1 = sector[a].second;
                        int x2 = sector[b].first, y2 = sector[b].second;
                        if ((x2 < x1 && x1 < y2) || (x2 < y1 && y1 < y2)) {
                            dist[a][b] = true;
                        }
                        if (dist[a][c] && dist[c][b]) {
                            dist[a][b] = true;
                        }
                    }
                }
            }
        } else {
            if (dist[x][y]) {
                std::cout << "1\n";
            } else {
                std::cout << "0\n";
            }
        }
    }
    return 0;
}
