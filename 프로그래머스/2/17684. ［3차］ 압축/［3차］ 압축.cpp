#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> dictionary;

vector<int> solution(string msg) {
    vector<int> answer;
    int mapSize = 26;
    char alphabet = 'A';
    int dictionaryIndex = 1;
    for (; alphabet <= 'Z'; alphabet++, dictionaryIndex++) {
        string key(1, alphabet);
        dictionary[key] = dictionaryIndex;
    }
    
    while (!msg.empty()) {
        for (int i = 0; i < msg.size(); i++) {
            int endIndex = i;
            string token(1, msg[i]);
            while (dictionary.find(token) != dictionary.end()) {
                endIndex++;
                token.push_back(msg[endIndex]);
                if (endIndex == msg.size()) {
                    break;
                }
            }
            token.pop_back();
            answer.push_back(dictionary[token]);
            token.push_back(msg[endIndex]);
            dictionary[token] = ++mapSize;
            msg.erase(i, token.size() - 1);
            break;
        }
    }
    
    return answer;
}