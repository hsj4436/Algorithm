#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, pair<int, int>> stageInformations;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    for (int i = 1; i < N + 1; i++) {
        stageInformations[i] = {0, 0};
    }
    
    for (int stage : stages) {
        for (int i = 1; i < min(N + 1, stage + 1); i++) {
            stageInformations[i].second++;
        }
        if (stage == N + 1) {
            continue;
        }
        stageInformations[stage].first++;
    }
    
    
    vector<pair<int, double>> fail;
    for (auto p : stageInformations) {
        if (p.second.second == 0 || p.second.first == 0) {
            fail.push_back({p.first, 0.0});
        } else {
            fail.push_back({p.first, (double)p.second.first / (double)p.second.second});
        }
    }
    
    sort(fail.begin(), fail.end(), [&](pair<int, double> a, pair<int, double> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    });
    
    for (auto p : fail) {
        answer.push_back(p.first);
    }
    
    return answer;
}