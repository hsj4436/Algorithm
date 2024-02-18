#include <iostream>
#include <vector>
#include <map>

int T, N;
std::map<int, int> team_size;
std::vector<int> teams[201];
int not_include[1001];

int main() {
    std::cin >> T;

    for (int tc = 0; tc < T; tc++) {
        std::cin >> N;

        team_size.clear();
        for (int i = 1; i < 201; i++) {
            teams[i].clear();
        }
        std::fill(not_include, not_include + 1001, 0);

        int last_team = 0;
        int team;
        for (int i = 1; i < N + 1; i++) {
            std::cin >> team;
            team_size[team]++;
            teams[team].push_back(i);
            last_team = std::max(team, last_team);
        }

        for (int i = 1; i < last_team + 1; i++) {
            if (team_size[i] != 6) {
                for (int j : teams[i]) {
                    not_include[j]++;
                }
            }
        }
        int excluded = 0;
        for (int i = 1; i < N + 1; i++) {
            if (not_include[i] != 0) {
                int temp = excluded + not_include[i];
                not_include[i] += excluded;
                excluded = temp;
            } else {
                not_include[i] += excluded;
            }
        }

        int winner = 0;
        int min_score = 987654321;
        int fifth_score = 1001;
        for (int i = 1; i < last_team + 1; i++) {
            if (team_size[i] != 6) {
                continue;
            }
            int score = 0;
            for (int j = 0; j < 4; j++) {
                score += teams[i][j] - not_include[teams[i][j]];
            }
            if (score < min_score) {
                winner = i;
                min_score = score;
                fifth_score = teams[i][4];
            } else if (score == min_score && teams[i][4] < fifth_score) {
                winner = i;
                min_score = score;
                fifth_score = teams[i][4];
            }
        }

        std::cout << winner << "\n";
    }

    return 0;
}