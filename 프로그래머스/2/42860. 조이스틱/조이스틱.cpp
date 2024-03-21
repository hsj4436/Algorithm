#include <string>
#include <vector>

using namespace std;

string target;

int backTrack(int index, string current) {
    if (current == target) {
        return 0;
    }
    int minMove = 100001;
    
    // moveRight
    int rightIndex = index;
    int moveCount = 0;
    while (true) {
        if (current[rightIndex] == target[rightIndex]) {
            rightIndex++;
            moveCount++;
            rightIndex %= target.size();
            continue;
        }
        char alphabet = current[rightIndex];
        int up = 0;
        while (alphabet != target[rightIndex]) {
            alphabet++;
            up++;
            if (alphabet > 'Z') {
                alphabet = 'A';
            }
        }
        int down = 0;
        alphabet = current[rightIndex];
        while (alphabet != target[rightIndex]) {
            alphabet--;
            down++;
            if (alphabet < 'A') {
                alphabet = 'Z';
            }
        }
        string nextName = current;
        nextName[rightIndex] = target[rightIndex];
        int temporalMove = moveCount + min(up, down) + backTrack(rightIndex, nextName);
        minMove = min(minMove, temporalMove);
        break;
    }
    
    // moveLeft
    int leftIndex = index - 1;
    if (leftIndex < 0) {
        leftIndex = target.size() - 1;
    }
    moveCount = 1;
    while (true) {
        if (current[leftIndex] == target[leftIndex]) {
            leftIndex--;
            moveCount++;
            leftIndex += target.size();
            leftIndex %= target.size();
            continue;
        }
        char alphabet = current[leftIndex];
        int up = 0;
        while (alphabet != target[leftIndex]) {
            alphabet++;
            up++;
            if (alphabet > 'Z') {
                alphabet = 'A';
            }
        }
        int down = 0;
        alphabet = current[leftIndex];
        while (alphabet != target[leftIndex]) {
            alphabet--;
            down++;
            if (alphabet < 'A') {
                alphabet = 'Z';
            }
        }
        string nextName = current;
        nextName[leftIndex] = target[leftIndex];
        int temporalMove = moveCount + min(up, down) + backTrack(leftIndex, nextName);
        minMove = min(minMove, temporalMove);
        break;
    }
    
    return minMove;
}

int solution(string name) {
    int answer = 0;
    target = name;
    string current(name.size(), 'A');
    answer = backTrack(0, current);
    
    return answer;
}