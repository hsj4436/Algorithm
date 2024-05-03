#include <string>
#include <vector>

using namespace std;

int N;
string P;

bool isWeightedString(string s) {
    int opened = 0, closed = 0;
    for (char ch : s) {
        if (ch == '(') {
            opened++;
        } else {
            closed++;
        }
    }
    
    return (opened == closed);
}

string modifyU(string u) {
    string result = u.substr(1);
    result.pop_back();
    for (char &ch : result) {
        if (ch == '(') {
            ch = ')';
        } else {
            ch = '(';
        }
    }
    return result;
}

bool isRightString(string s) {
    vector<char> stack;
    for (char ch : s) {
        if (ch == '(') {
            stack.push_back(ch);
        } else {
            if (stack.empty()) {
                return false;
            }
            stack.pop_back();
        }
    }
    if (stack.empty()) {
        return true;
    }
    return false;
}

string sol(string w) {
    if (w.empty()) {
        return w;
    }
    string u, v;
    for (int i = 0; i < w.size(); i++) {
        u.push_back(w[i]);
        string tempV = w.substr(i + 1);
        if (isWeightedString(u) && isWeightedString(tempV)) {
            v = tempV;
            break;
        }
    }
    
    if (isRightString(u)) {
        u += sol(v);
        return u;
    }
    
    string newU = "(" + sol(v) + ")" + modifyU(u);
    return newU;
}

string solution(string p) {
    string answer = "";
    
    if (p.empty() || isRightString(p)) {
        return p;
    }
    
    answer = sol(p);
    
    return answer;
}