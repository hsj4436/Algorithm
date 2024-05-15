#include <iostream>
#include <set>

int R, C;
std::string board[1001];

int main() {
    std::cin >> R >> C;

    std::string row;
    for (int i = 0; i < R; i++) {
        std::cin >> row;
        for (int j = 0; j < C; j++) {
            board[j].push_back(row[j]);
        }
    }

    int answer = 0;
    for (int i = 0; i < R; i++) {
        std::set<std::string> set;
        for (int j = 0; j < C; j++) {
            set.insert(board[j]);
        }
        if (set.size() == C) {
            answer++;
            for (int j = 0; j < C; j++) {
                board[j].erase(0, 1);
            }
        } else {
            break;
        }
    }

    std::cout << answer - 1 << "\n";

    return 0;
}
