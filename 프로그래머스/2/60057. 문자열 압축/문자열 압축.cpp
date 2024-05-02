#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 987654321;
    
    for (int unitSize = 1; unitSize < s.size() + 1; unitSize++) {
        string compressed;
        string lastToken;
        int tokenCount = 0;
        for (int i = 0; i < s.size(); i += unitSize) {
            if (lastToken.empty()) {
                lastToken = s.substr(i, unitSize);
                tokenCount = 1;
                continue;
            }
            string token = s.substr(i, unitSize);
            
            if (token != lastToken) {
                if (tokenCount > 1) {
                    compressed += to_string(tokenCount);
                }
                compressed += lastToken;
                lastToken = token;
                tokenCount = 1;
            } else {
                tokenCount++;
            }
        }
        
        if (tokenCount > 1) {
            compressed += to_string(tokenCount);
        }
        compressed += lastToken;
        
        if (compressed.size() < answer) {
            answer = compressed.size();
        }
    }
    
    return answer;
}