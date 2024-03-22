#include <string>
#include <vector>

using namespace std;

int answer = 0;

int K;
bool selected[8];
vector<vector<int>> dungeon;

void combination(int played) {
    answer = max(answer, played);
    
    for (int i = 0; i < dungeon.size(); i++) {
        if (selected[i]) {
            continue;
        }
        if (K < dungeon[i][0]) {
            continue;
        }
        K -= dungeon[i][1];
        selected[i] = true;
        combination(played + 1);
        selected[i] = false;
        K += dungeon[i][1];
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    K = k;
    dungeon = dungeons;
    combination(0);
    return answer;
}