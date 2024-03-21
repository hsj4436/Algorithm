#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    string current(name.size(), 'A');
    int index = 0;
    while (current != name) {
        int minMove = 1000001;
        int minIndex = 0;
        for (int i = 0; i < name.size(); i++) {
            if (current[i] == name[i]) {
                continue;
            }
            int minLeftRight = max(i, index) - min(i, index);
            if (i > index) {
                minLeftRight = min(minLeftRight, index + (int)name.size() - i);
            } else {
                minLeftRight = min(minLeftRight, (int)name.size() - index + i);
            }
            char alphabet = current[i];
            int up = 0;
            while (alphabet != name[i]) {
                alphabet++;
                up++;
                if (alphabet > 'Z') {
                    alphabet = 'A';
                }
            }
            int down = 0;
            alphabet = current[i];
            while (alphabet != name[i]) {
                alphabet--;
                down++;
                if (alphabet < 'A') {
                    alphabet = 'Z';
                }
            }
            if (min(up, down) + minLeftRight < minMove) {
                minMove = min(up, down) + minLeftRight;
                minIndex = i;
            }
        }
        
        answer += minMove;
        index = minIndex;
        current[index] = name[index];
    }
    
    return answer;
}