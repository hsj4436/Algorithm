#include <iostream>
#include <queue>

int N, T, G;
bool visited[100000];

int main() {
    std::cin >> N >> T >> G;

    std::queue<std::pair<int, int>> q;
    q.push({0, N});
    visited[N] = true;

    while (!q.empty()) {
        int pressed = q.front().first;
        int cur = q.front().second;
        q.pop();

        if (pressed > T) {
            break;
        }
        
        if (cur == G) {
            std::cout << pressed << "\n";
            return 0;
        }


        if (cur + 1 < 100000 && !visited[cur + 1]) {
            visited[cur + 1] = true;
            q.push({pressed + 1, cur + 1});
        }

        if (cur != 0 && cur * 2 < 100000) {
            std::string next = std::to_string(cur * 2);
            for (int i = 0; i < next.size(); i++) {
                if (next[i] != '0') {
                    next[i]--;
                    break;
                }
            }
            int nextNumber = std::stoi(next);
            if (!visited[nextNumber]) {
                q.push({pressed + 1, nextNumber});
            }
        }
    }

    std::cout << "ANG\n";

    return 0;
}
