#include <iostream>

int N, S, R;
std::pair<bool, bool> team[11]; // {damaged, reserved}
int borrow_to[11];
bool borrowed[11];

int main() {
    std::cin >> N >> S >> R;

    int team_number = 0;
    for (int i = 0; i < S; i++) {
        std::cin >> team_number;
        team[team_number].first = true;
    }

    for (int i = 0; i < R; i++) {
        std::cin >> team_number;
        team[team_number].second = true;
        if (team[team_number].first) {
            team[team_number].first = false;
            team[team_number].second = false;
        }
    }

    int answer = 0;
    for (int i = 1; i < N + 1; i++) {
        if (team[i].first && !team[i].second) {
            if (i < N && !team[i + 1].first && team[i + 1].second && !borrowed[i]) {
                borrowed[i] = true;
                borrow_to[i + 1] = i;
            }
            if (!borrowed[i]) {
                answer++;
            }
        } else if (team[i].second){
            if (borrow_to[i] == 0) {
                if (i < N && team[i + 1].first && !team[i + 1].second) {
                    borrowed[i + 1] = true;
                    borrow_to[i] = i + 1;
                }
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}
