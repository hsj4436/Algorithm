#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, vector<int>> queryCases;

vector<string> languages{"cpp", "java", "python", "-"};
vector<string> jobs{"backend", "frontend", "-"};
vector<string> careers{"junior", "senior", "-"};
vector<string> foods{"chicken", "pizza", "-"};

void makeCases() {
    for (string language : languages) {
        for (string job : jobs) {
            for (string career : careers) {
                for (string food : foods) {
                    queryCases[language + job + career + food] = vector<int>();
                }
            }
        }
    }
}

void makeQueryCases(string language, string job, string career, string food, int score) {
    vector<string> ls{language, "-"};
    vector<string> js{job, "-"};
    vector<string> cs{career, "-"};
    vector<string> fs{food, "-"};
    for (string l : ls) {
        for (string j : js) {
            for (string c : cs) {
                for (string f : fs) {
                    queryCases[l + j + c + f].push_back(score);
                }
            }
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    makeCases();
    for (string i : info) {
        stringstream ss(i);
        string language, job, career, food;
        int score;
        ss >> language >> job >> career >> food >> score;
        makeQueryCases(language, job, career, food, score);
    }
    for (auto &p : queryCases) {
        sort(p.second.begin(), p.second.end());
    }
    
    for (string q : query) {
        string Q;
        stringstream ss(q);
        string token;
        while (getline(ss, token, ' ')) {
            if (token != "and" && !('0' <= token[0] && token[0] <= '9')) {
                Q += token;
            }
        }
        int score = stoi(token);
        
        if (queryCases[Q].empty()) {
            answer.push_back(0);
        } else {
            answer.push_back(queryCases[Q].end() - lower_bound(queryCases[Q].begin(), queryCases[Q].end(), score));
        }
    }
    return answer;
}