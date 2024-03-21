#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int erased = 0;
    for (int i = 0; i < number.size(); i++) {
        if (answer.empty() || erased == k) {
            answer.push_back(number[i]);
        } else if (answer.back() < number[i]) {
            while (!answer.empty()) {
                if (answer.back() < number[i]) {
                    answer.pop_back();
                    erased++;
                    if (erased == k) {
                        break;
                    }
                } else {
                    break;
                }
            }
            answer.push_back(number[i]);
        } else {
            answer.push_back(number[i]);
        }
    }
    if (erased < k) {
        while (erased != k) {
            answer.pop_back();
            erased++;
        }
    }
    return answer;
}