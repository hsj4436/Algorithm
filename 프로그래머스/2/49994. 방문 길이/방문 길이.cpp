#include <string>

#define MAX 10
#define MIN 0

using namespace std;

int answer = 0;
string dir;
bool visited[121][121];

void sol(int index, int x, int y) {
    if (index == dir.size()) {
        return;
    }
    int cur = 11 * x + y;
    char direction = dir[index];
    if (direction == 'U') {
        if (x - 1 >= MIN) {
            int next = 11 * (x - 1) + y;
            if (!visited[cur][next]) {
                answer++;
                visited[cur][next] = true;
                visited[next][cur] = true;
            }
            sol(index + 1, x - 1, y);
        } else {
            sol(index + 1, x, y);
        }
    } else if (direction == 'D') {
        if (x + 1 <= MAX) {
            int next = 11 * (x + 1) + y;
            if (!visited[cur][next]) {
                answer++;
                visited[cur][next] = true;
                visited[next][cur] = true;
            }
            sol(index + 1, x + 1, y);
        } else {
            sol(index + 1, x, y);
        }
    } else if (direction == 'R') {
        if (y + 1 <= MAX) {
            int next = 11 * x + y + 1;
            if (!visited[cur][next]) {
                answer++;
                visited[cur][next] = true;
                visited[next][cur] = true;
            }
            sol(index + 1, x, y + 1);
        } else {
            sol(index + 1, x, y);
        }
    } else {
        if (y - 1 >= MIN) {
            int next = 11 * x + y - 1;
            if (!visited[cur][next]) {
                answer++;
                visited[cur][next] = true;
                visited[next][cur] = true;
            }
            sol(index + 1, x, y - 1);
        } else {
            sol(index + 1, x, y);
        }
    }
}

int solution(string dirs) {
    dir = dirs;
    sol(0, 5, 5);
    return answer;
}