#include <string>
#include <vector>

using namespace std;

int skillIndex[26];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < 26; i++) {
        skillIndex[i] = -1;
    }
    for (int i = 0; i < skill.size(); i++) {
        skillIndex[skill[i] - 'A'] = i;
    }
    
    for (string skillTree : skill_trees) {
        int index = 0;
        bool possible = true;
        for (char s : skillTree) {
            if (skillIndex[s - 'A'] != -1 && skillIndex[s - 'A'] > index) {
                possible = false;
                break;
            }
            if (index < skill.size() && s == skill[index]) {
                index++;
            }
        }
        if (possible) {
            answer++;
        }
    }
    
    return answer;
}