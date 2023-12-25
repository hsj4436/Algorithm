#include <iostream>

int T;
int M, N;

int main() {
    std::cin >> T;

    for (int test_case = 0; test_case < T; test_case++) {
        std::cin >> M >> N;

        int grid[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> grid[i][j];
            }
        }

        int answer = 0;
        for (int i = 0; i < N; i++) {
            int last_bottom = M - 1;
            for (int j = M - 1; j > -1; j--) {
                if (grid[j][i] == 1) {
                    grid[last_bottom][i] = 1;
                    grid[j][i] = 0;
                    answer += std::abs(j - last_bottom);
                    last_bottom--;
                }
            }
        }

        std::cout << answer << "\n";
    }
    return 0;
}
