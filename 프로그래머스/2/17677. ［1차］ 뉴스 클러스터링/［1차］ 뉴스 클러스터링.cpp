#include <string>
#include <set>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    map<string, int> m1, m2;
    for (int i = 0; i < str1.size() - 1; i++) {
        if (!('a' <= str1[i] && str1[i] <= 'z') && !('A' <= str1[i] && str1[i] <= 'Z')) {
            continue;
        }
        if (!('a' <= str1[i + 1] && str1[i + 1] <= 'z') && !('A' <= str1[i + 1] && str1[i + 1] <= 'Z')) {
            continue;
        }
        string token = str1.substr(i, 2);
        for (auto &ch : token) {
            ch = tolower(ch);
        }
        m1[token]++;
    }
    
    for (int i = 0; i < str2.size() - 1; i++) {
        if (!('a' <= str2[i] && str2[i] <= 'z') && !('A' <= str2[i] && str2[i] <= 'Z')) {
            continue;
        }
        if (!('a' <= str2[i + 1] && str2[i + 1] <= 'z') && !('A' <= str2[i + 1] && str2[i + 1] <= 'Z')) {
            continue;
        }
        string token = str2.substr(i, 2);
        for (auto &ch : token) {
            ch = tolower(ch);
        }
        m2[token]++;
    }
    
    double head = 0.0, tail = 0.0;
    for (auto p : m1) {
        if (m2[p.first] != 0) {
            head += min(m1[p.first], m2[p.first]);
            tail += max(m1[p.first], m2[p.first]);
        } else {
            tail += m1[p.first];
        }
    }
    for (auto p : m2) {
        if (m1[p.first] == 0) {
            tail += m2[p.first];
        }
    }
    
    double jaccard = 0.0;
    if (m1.size() == 0 && m2.size() == 0) {
        jaccard = 1.0;
    } else {
        jaccard = head / tail;
    }
    jaccard *= 65536;
    answer = (int)jaccard;
    
    return answer;
}