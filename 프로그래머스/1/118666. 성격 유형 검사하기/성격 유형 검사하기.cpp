#include <string>
#include <vector>
#include <map>

using namespace std;

char indicator[4][2] = {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};
map<char, int> score;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for (int i = 0; i < choices.size(); i++) {
        if (choices[i] < 4) {
            score[survey[i][0]] += -(choices[i] - 4);
        } else if (choices[i] > 4) {
            score[survey[i][1]] += choices[i] - 4;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (score[indicator[i][0]] >= score[indicator[i][1]]) {
            answer.push_back(indicator[i][0]);
        } else {
            answer.push_back(indicator[i][1]);
        }
    }
    return answer;
}