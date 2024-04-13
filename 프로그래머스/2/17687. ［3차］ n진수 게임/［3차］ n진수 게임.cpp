#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int number = 0;
    int person = 0;
    if (person + 1 == p) {
        answer.push_back('0');
    }
    number = 1;
    person = 1;
    while (answer.size() != t) {
        string converted;
        int numberCopy = number;
        while (numberCopy != 0) {
            int mod = numberCopy % n;
            if (mod < 10) {
                converted.push_back(mod + '0');
            } else {
                converted.push_back(mod - 10 + 'A');
            }
            numberCopy /= n;
        }
        reverse(converted.begin(), converted.end());
        for (char ch : converted) {
            if (person + 1 == p) {
                answer.push_back(ch);
            }
            if (answer.size() == t) {
                break;
            }
            person++;
            person %= m;
        }
        number++;
    }
    
    return answer;
}