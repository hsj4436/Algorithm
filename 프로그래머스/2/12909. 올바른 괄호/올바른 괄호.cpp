#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    vector<char> stk;
    for (char ch : s) {
        if (ch == '(') {
            stk.push_back(ch);
        } else {
            if (stk.empty()) {
                return false;
            } else {
                stk.pop_back();
            }
        }
    }
    
    if (!stk.empty()) {
        return false;
    }

    return answer;
}