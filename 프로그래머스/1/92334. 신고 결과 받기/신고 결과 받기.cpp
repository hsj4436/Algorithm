#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> reportCount;
map<string, map<string, bool>> reportHistory;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for (string rep : report) {
        auto it = rep.find(" ");
        string reporter = rep.substr(0, it);
        string reported = rep.substr(it + 1);
        if (!reportHistory[reporter][reported]) {
            reportHistory[reporter][reported] = true;
            reportCount[reported]++;
        }
    }
    
    vector<string> confirmedReport;
    for (auto p : reportCount) {
        if (p.second >= k) {
            confirmedReport.push_back(p.first);
        }
    }
    
    for (string id : id_list) {
        int mailCount = 0;
        for (auto p : reportHistory[id]) {
            if (find(confirmedReport.begin(), confirmedReport.end(), p.first) != confirmedReport.end()) {
                mailCount++;
            }    
        }
        answer.push_back(mailCount);
    }
    
    return answer;
}