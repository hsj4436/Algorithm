#include <iostream>
#include <queue>

int S;
int visited[1001][1001];
struct state {
    int cur;
    int clip_board;
    int clicked;
    state(int cur, int clipBoard, int clicked) : cur(cur), clip_board(clipBoard), clicked(clicked) {}
};

int main() {
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            visited[i][j] = 987654321;
        }
    }
    std::cin >> S;

    std::queue<state> q;
    q.push({1, 0, 0});
    visited[1][0] = 0;

    while (!q.empty()) {
        int cur = q.front().cur;
        int clip_board = q.front().clip_board;
        int clicked = q.front().clicked;
        q.pop();

        if (clip_board != 0) {
            if (cur + clip_board >= S) {
                if (clicked + cur + clip_board - S + 1 < visited[S][clip_board]) {
                    visited[S][clip_board] = clicked + cur + clip_board - S + 1;
                    continue;
                }
            } else {
                if (clicked + 1 < visited[cur + clip_board][clip_board]) {
                    visited[cur + clip_board][clip_board] = clicked + 1;
                    q.push(state(cur + clip_board, clip_board, clicked + 1));
                }
            }
        }

        if (cur != clip_board) {
            q.push(state(cur, cur, clicked + 1));
        }

        if (cur > 0) {
            if (clicked + 1 < visited[cur - 1][clip_board]) {
                visited[cur - 1][clip_board] = clicked + 1;
                q.push(state(cur - 1, clip_board, clicked + 1));
            }
        }
    }

    int answer = 987654321;
    for (int i = 0; i < 1001; i++) {
        answer = std::min(answer, visited[S][i]);
    }
    std::cout << answer << "\n";

    return 0;
}
