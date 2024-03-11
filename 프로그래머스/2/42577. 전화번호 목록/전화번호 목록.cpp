#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, vector<string>> phoneBook;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for (string phoneNumber : phone_book) {
        phoneBook[phoneNumber[0] - '0'].push_back(phoneNumber);
    }
    
    for (auto p : phoneBook) {
        sort(p.second.begin(), p.second.end());
        for (int i = 0; i < p.second.size(); i++) {
            if (i < p.second.size() - 1) {
                if (p.second[i + 1].substr(0, p.second[i].size()) == p.second[i]) {
                    return false;
                }
            }
        }
    }
    return answer;
}