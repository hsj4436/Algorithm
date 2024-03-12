#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    map<string, vector<string>> cloth;
    for (vector<string> vs : clothes) {
        cloth[vs[1]].push_back(vs[0]);
    }
    
    if (cloth.size() == 1) {
        return (*cloth.begin()).second.size();
    }
    
    auto it = cloth.begin();
    for (; it != cloth.end(); it++) {
        for (int i = 0; i < (*it).second.size(); i++) {
            int combinations = 1;
            auto j = it;
            j++;
            for (; j != cloth.end(); j++) {
                combinations *= ((*j).second.size() + 1);
            }
            answer += combinations;
        }
    }
    
    return answer;
}