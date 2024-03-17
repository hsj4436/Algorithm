#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> stringNumbers;
    for (int n : numbers) {
        stringNumbers.push_back(to_string(n));
    }
    sort(stringNumbers.begin(), stringNumbers.end(), [&](string a, string b) {
        return a + b > b + a;
    });
    
    for (string n : stringNumbers) {
        answer += n;
    }
    while (true) {
        if (answer.size() == 1 || answer[0] != '0') {
            break;
        }
        answer.erase(0, 1);
    }
    return answer;
}