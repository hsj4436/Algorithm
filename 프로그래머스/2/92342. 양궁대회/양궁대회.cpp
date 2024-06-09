#include <string>
#include <vector>

using namespace std;

vector<int> apeach;
int maxScoreDiff = 0;
vector<int> lion(11, 0);
vector<int> answer(11, 0);

void backTrack(int lastArrow, int curScore) {
    if (curScore == 0) {
        if (lastArrow != 0) {
            lion[10 - curScore] = lastArrow;
        }
        int lionScore = 0, apeachScore = 0;
        for (int i = 0; i <= 10; i++) {
            if (apeach[i] != 0 && apeach[i] >= lion[i]) {
                apeachScore += 10 - i;
            } else if (lion[i] != 0 && lion[i] > apeach[i]) {
                lionScore += 10 - i;
            }
        }
        if (lionScore - apeachScore > maxScoreDiff) {
            maxScoreDiff = lionScore - apeachScore;
            answer = lion;
        } else if (lionScore - apeachScore > 0 && lionScore - apeachScore == maxScoreDiff) {
            for (int i = 10; i > -1; i--) {
                if (lion[i] < answer[i]) {
                    break;
                } else if (lion[i] > answer[i]) {
                    answer = lion;
                    break;
                }
            }
        }
        lion[10 - curScore] = 0;
        return;
    }
    
    for (int i = 0; i <= min(lastArrow, apeach[10 - curScore] + 1); i++) {
        lion[10 - curScore] = i;
        backTrack(lastArrow - i, curScore - 1);
    }
    lion[10 - curScore] = 0;
}

vector<int> solution(int n, vector<int> info) {
    apeach = info;
    backTrack(n, 10);
    if (maxScoreDiff == 0) {
        answer.clear();
        answer.push_back(-1);
    }
    return answer;
}