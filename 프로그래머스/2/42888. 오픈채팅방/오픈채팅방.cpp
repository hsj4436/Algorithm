#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

map<string, string> stateMap;
map<string, pair<string, vector<pair<int, string>>>> userRecord; // {ID, {NickName, [{index, state}]}}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    stateMap["Enter"] = "님이 들어왔습니다.";
    stateMap["Leave"] = "님이 나갔습니다.";
    
    for (int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        string state, id, nickname;
        getline(ss, state, ' ');
        getline(ss, id, ' ');
        getline(ss, nickname, ' ');
        
        if (state == "Enter") {
            userRecord[id].first = nickname;
            userRecord[id].second.push_back({i, "Enter"});
        } else if (state == "Leave") {
            userRecord[id].second.push_back({i, "Leave"});
        } else {
            userRecord[id].first = nickname;
        }
    }
    
    vector<pair<int, string>> textRecord;
    for (auto p : userRecord) {
        string nickName = p.second.first;
        for (auto pp : p.second.second) {
            textRecord.push_back({pp.first, nickName + stateMap[pp.second]});
        }
    }
    
    sort(textRecord.begin(), textRecord.end(), [&](pair<int, string> a, pair<int, string> b) {
       return a.first < b.first; 
    });
    
    for (auto p : textRecord) {
        answer.push_back(p.second);
    }
    
    return answer;
}