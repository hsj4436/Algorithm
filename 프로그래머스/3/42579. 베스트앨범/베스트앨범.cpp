#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define PII pair<int, int>

using namespace std;

struct cmp {
    bool operator() (PII a, PII b) {
        if (a.second == b.second) {
            return a.first > b.first;
        } else {
            return a.second < b.second;
        }
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genreCount;
    map<string, priority_queue<PII, vector<PII>, cmp>> playCount;
    for (int i = 0; i < genres.size(); i++) {
        genreCount[genres[i]] += plays[i];
        playCount[genres[i]].push({i, plays[i]});
    }
    
    vector<pair<string, int>> genreCountVector(genreCount.begin(), genreCount.end());
    
    sort(genreCountVector.begin(), genreCountVector.end(), [&](pair<string, int> a, pair<string, int> b) {
       return a.second > b.second; 
    });
    
    for (int i = 0; i < genreCountVector.size(); i++) {
        int songs = 0;
        while (!playCount[genreCountVector[i].first].empty() && songs != 2) {
            answer.push_back(playCount[genreCountVector[i].first].top().first);
            playCount[genreCountVector[i].first].pop();
            songs++;
        }
    }
    
    return answer;
}