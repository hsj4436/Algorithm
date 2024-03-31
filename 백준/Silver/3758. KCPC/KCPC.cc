#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

struct team {
    int id;
    int score;
    int applyCount;
    int lastApply;
    team() {}
    team(int id, int score, int applyCount, int lastApply) : id(id), score(score), applyCount(applyCount), lastApply(lastApply) {}
};

int T;
int N, K, teamID, M;
std::map<int, std::map<int, int>> problems;

int main() {
    std::cin >> T;

    while (T--) {
        std::cin >> N >> K >> teamID >> M;
        problems.clear();
        std::vector<team> teams;
        for (int i = 1; i < N + 1; i++) {
            teams.push_back(team(i, 0, 0, 0));
        }

        for (int i = 0; i < M; i++) {
            int id, problem, score;
            std::cin >> id >> problem >> score;
            teams[id - 1].applyCount++;
            teams[id - 1].lastApply = i;
            if (score > problems[problem][id]) {
                teams[id - 1].score += score - problems[problem][id];
                problems[problem][id] = score;
            }
        }

        std::sort(teams.begin(), teams.end(), [&](team a, team b) {
           if (a.score == b.score) {
               if (a.applyCount == b.applyCount) {
                   return a.lastApply < b.lastApply;
               } else {
                   return a.applyCount < b.applyCount;
               }
           } else {
               return a.score > b.score;
           }
        });

        for (int i = 0; i < N; i++) {
            if (teams[i].id == teamID) {
                std::cout << i + 1 << "\n";
                break;
            }
        }
    }
    return 0;
}
