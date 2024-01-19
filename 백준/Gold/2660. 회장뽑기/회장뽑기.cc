#include <iostream>
#include <vector>

int N;
int dist[51][51];

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (i == j) {
                continue;
            }
            dist[i][j] = 987654321;
        }
    }

    int left = 0, right = 0;
    while (true) {
        std::cin >> left >> right;
        if (left == -1 && right == -1) {
            break;
        }
        dist[left][right] = 1;
        dist[right][left] = 1;
    }

    for (int k = 1; k < N + 1; k++) {
        for (int i = 1; i < N + 1; i++) {
            if (i == k) {
                continue;
            }
            for (int j = 1; j < N + 1; j++) {
                if (i == j || j == k) {
                    continue;
                }
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int score = 987654321;
    for (int i = 1; i < N + 1; i++) {
        int max_tmp = 0;
        for (int j = 1; j < N + 1; j++) {
            max_tmp = std::max(dist[i][j], max_tmp);
        }
        score = std::min(score, max_tmp);
    }

    std::vector<int> answer;
    for (int i = 1; i < N + 1; i++) {
        bool possible = true;
        for (int j = 1; j < N + 1; j++) {
            if (dist[i][j] > score) {
                possible = false;
                break;
            }
        }
        if (possible) {
            answer.push_back(i);
        }
    }

    std::cout << score << " " << answer.size() << "\n";
    for (auto i : answer) {
        std::cout << i << " ";
    }

    return 0;
}
