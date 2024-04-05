#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<string> sets;
    int index = 1;
    string currentSet(1, dartResult[0]);
    while (index != dartResult.size()) {
        if ('0' <= dartResult[index] && dartResult[index] <= '9') {
            if (dartResult[index] == '0' && dartResult[index - 1] == '1') {
                currentSet.push_back(dartResult[index]);
                index++;
                continue;
            }
            sets.push_back(currentSet);
            currentSet = "";
            currentSet.push_back(dartResult[index]);
            index++;
            continue;
        }
        currentSet.push_back(dartResult[index]);
        index++;
    }
    sets.push_back(currentSet);
    
    int scores[3];
    for (int i = 0; i < 3; i++) {
        string current = sets[i];
        int score = 0;
        char bonus = 'X', option = 'X';
        if (current.back() == '*' || current.back() == '#') {
            option = current.back();
            current.pop_back();
        }
        if ('A' <= current.back() && current.back() <= 'Z') {
            bonus = current.back();
            current.pop_back();
        }
        score = stoi(current);
        if (bonus == 'D') {
            score *= score;    
        } else if (bonus == 'T') {
            score *= score * score;
        }
        if (option == '*') {
            if (i > 0) {
                scores[i - 1] *= 2;
            }
            score *= 2;
        } else if (option == '#') {
            score *= -1;
        }
        scores[i] = score;
    }
    
    for (int score : scores) {
        answer += score;
    }
    
    return answer;
}