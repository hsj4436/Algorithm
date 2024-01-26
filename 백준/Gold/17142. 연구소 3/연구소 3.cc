#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define PII std::pair<int, int>

int N, M;
int lab[51][51];
bool visited[51][51];
std::vector<PII> viruses;
bool activated[11];
std::vector<PII> active_viruses;
int blanks = 0;
int answer = 987654321;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void spread() {
    std::memset(visited, false, sizeof(visited));
    std::priority_queue<std::pair<int, PII>> pq;
    for (PII virus : active_viruses) {
        visited[virus.first][virus.second] = true;
        pq.push({0, virus});
    }

    int t = 0, filled = 0;
    while (!pq.empty()) {
        if (t > answer) {
            return;
        }
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cur = -pq.top().first;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
                continue;
            }

            if (visited[nx][ny] || lab[nx][ny] == 1) {
                continue;
            }
            visited[nx][ny] = true;
            if (lab[nx][ny] == 0) {
                filled++;
                t = cur + 1;
            }
            pq.push({-(cur + 1), {nx, ny}});
        }
    }

    if (filled == blanks) {
        answer = std::min(answer, t);
    }
}

void select_virus(int index, int selected) {
    if (selected == M) {
        spread();
        return;
    }
    for (int i = index; i < viruses.size(); i++) {
        if (!activated[i]) {
            activated[i] = true;
            active_viruses.push_back(viruses[i]);
            select_virus(i + 1, selected + 1);
            activated[i] = false;
            active_viruses.pop_back();
        }
    }
}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> lab[i][j];
            if (lab[i][j] == 2) {
                viruses.push_back({i, j});
            } else if (lab[i][j] == 0) {
                blanks++;
            }
        }
    }

    if (blanks == 0) {
        if (viruses.empty()) {
            std::cout << "-1\n";
        } else {
            std::cout << "0\n";
        }
        return 0;
    }

    select_virus(0, 0);

    if (answer == 987654321) {
        std::cout << "-1\n";
    } else {
        std::cout << answer << "\n";
    }

    return 0;
}