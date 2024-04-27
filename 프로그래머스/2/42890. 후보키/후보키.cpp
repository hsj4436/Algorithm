#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int columns;
vector<string> candidateKeys;
vector<string> keys;

void combination(int index, string key) {
    for (int i = index; i < columns; i++) {
        key.push_back(i + '0');
        keys.push_back(key);
        combination(i + 1, key);
        key.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    columns = relation[0].size();
    combination(0, "");
    
    sort(keys.begin(), keys.end(), [&](string a, string b) {
        if (a.size() == b.size()) {
            return a < b;
        } else {
            return a.size() < b.size();
        }
    });

    for (string key : keys) {
        bool possibleKey = true;
        for (auto candidateKey : candidateKeys) {
            int matchCount = 0;
            for (int i = 0; i < candidateKey.size(); i++) {
                if (key.find(candidateKey[i]) != string::npos) {
                    matchCount++;
                }
            }
            if (matchCount == candidateKey.size()) {
                possibleKey = false;
                break;
            }
        }
        if (!possibleKey) {
            continue;
        }
        map<string, int> count;
        for (vector<string> tuple : relation) {
            int keyIndex = 0;
            string identify;
            for (int i = 0; i < tuple.size(); i++) {
                if (key[keyIndex] - '0' == i) {
                    identify += tuple[i];
                    keyIndex++;
                    if (keyIndex == key.size()) {
                        break;
                    }
                }
            }
            count[identify]++;
            if (count[identify] > 1) {
                possibleKey = false;
                break;
            }
        }
        if (possibleKey) {
            candidateKeys.push_back(key);
        }
    }    
    
    answer = candidateKeys.size();
    return answer;
}