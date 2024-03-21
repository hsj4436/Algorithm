#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (int i = 0; i < k; i++) {
        bool erased = false;
        for (int j = 0; j < number.size() - 1; j++) {
            if (number[j] < number[j + 1]) {
                number.erase(j, 1);
                erased = true;
                break;
            }
        }
        if (!erased) {
            number.pop_back();
        }
    }
    answer = number;
    return answer;
}