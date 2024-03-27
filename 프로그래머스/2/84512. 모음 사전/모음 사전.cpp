#include <string>
#include <vector>

using namespace std;

bool isEnd = false;
int count = 0;
char vowels[5] = {'A', 'E', 'I', 'O', 'U'};

void makeDictionary(string word, string target) {
    if (word == target) {
        isEnd = true;
        return;
    }
    
    if (word.size() == 5) {
        return;
    }
    
    for (int i = 0; i < 5; i++) {
        count++;
        makeDictionary(word + vowels[i], target);
        if (isEnd) {
            return;
        }
    }
}

int solution(string word) {
    int answer = 0;
    makeDictionary("", word);
    answer = count;
    return answer;
}