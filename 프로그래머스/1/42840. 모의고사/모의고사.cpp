#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> supoja[3];
    while (true) {
        bool done = false;
        for (int i = 1; i < 6; i++) {
            supoja[0].push_back(i);
            if (supoja[0].size() == answers.size()) {
                done = true;
                break;
            }
        }
        if (done) {
            break;
        }
    }
    while (true) {
        bool done = false;
        for (int i = 1; i < 6; i++) {
            if (i == 2) {
                continue;
            }
            supoja[1].push_back(2);
            if (supoja[1].size() == answers.size()) {
                done = true;
                break;
            }
            supoja[1].push_back(i);
            if (supoja[1].size() == answers.size()) {
                done = true;
                break;
            }
        }
        if (done) {
            break;
        }
    }
    while (true) {
        bool done = false;
        supoja[2].push_back(3);
        if (supoja[2].size() == answers.size()) {
            done = true;
            break;
        }
        supoja[2].push_back(3);
        if (supoja[2].size() == answers.size()) {
            done = true;
            break;
        }
        for (int i = 1; i < 6; i++) {
            if (i == 3) {
                continue;
            }
            supoja[2].push_back(i);
            if (supoja[2].size() == answers.size()) {
                done = true;
                break;
            }
            supoja[2].push_back(i);
            if (supoja[2].size() == answers.size()) {
                done = true;
                break;
            }
        }
        if (done) {
            break;
        }
    }
    
    vector<int> count(3, 0);
    int maxCount = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (supoja[0][i] == answers[i]) {
            count[0]++;
            maxCount = max(maxCount, count[0]);
        }
        if (supoja[1][i] == answers[i]) {
            count[1]++;
            maxCount = max(maxCount, count[1]);
        }
        if (supoja[2][i] == answers[i]) {
            count[2]++;
            maxCount = max(maxCount, count[2]);
        }
    }
    
    for (int i = 0; i < 3; i++) {
        if (count[i] == maxCount) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}