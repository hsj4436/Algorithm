#include <iostream>
#include <vector>

int N, M;
long long cities[101][101];
int from[101][101];
std::vector<int> v;

void path(int i, int j) {
    if (from[i][j] != 0) {
        path(i, from[i][j]);
        v.push_back(from[i][j]);
        path(from[i][j], j);
    }
}
int main() {
    std::cin >> N >> M;

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (i == j) {
                cities[i][j] = 0;
            } else {
                cities[i][j] = 987654321;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        long long a, b, c;
        std::cin >> a >> b >> c;
        cities[a][b] = std::min(cities[a][b], c);
    }

    for (int k = 1; k < N + 1; k++) {
        for (int i = 1; i < N + 1; i++) {
            if (i == k) {
                continue;
            }
            for (int j = 1; j < N + 1; j++) {
                if (i == j || k == j) {
                    continue;
                }
                if (cities[i][k] + cities[k][j] < cities[i][j]) {
                    cities[i][j] = cities[i][k] + cities[k][j];
                    from[i][j] = k;
                }
            }
        }
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (cities[i][j] == 987654321) {
                std::cout << "0 ";
            } else {
                std::cout << cities[i][j] << " ";
            }
        }
        std::cout << "\n";
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (cities[i][j] == 987654321 || cities[i][j] == 0) {
                std::cout << "0\n";
            } else {
                path(i, j);
                std::cout << v.size() + 2 << " " << i << " ";
                for (auto city : v) {
                    std::cout << city << " ";
                }
                std::cout << j << "\n";
                v.clear();
            }
        }
    }
    return 0;
}
