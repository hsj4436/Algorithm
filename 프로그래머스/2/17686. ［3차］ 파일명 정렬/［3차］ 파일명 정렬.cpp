#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct file {
    int index;
    string originName;
    string head;
    int number;
    string tail;
    file() {}
    file(int index, string originName, string head, int number, string tail) : index(index), originName(originName), head(head), number(number), tail(tail) {}
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<file> convertedFiles;
    for (int i = 0; i < files.size(); i++) {
        string head;
        string numberString;
        string tail;
        for (char ch : files[i]) {
            if (numberString.empty() && !('0' <= ch && ch <= '9')) {
                head.push_back(ch);
            } else if (('0' <= ch && ch <= '9') && tail.empty()) {
                numberString.push_back(ch);
            } else {
                tail.push_back(ch);
            }
        }
        convertedFiles.push_back(file(i, files[i], head, stoi(numberString), tail));
    }
    
    sort(convertedFiles.begin(), convertedFiles.end(), [&](file a, file b) {
        string aLowerHead = a.head;
        for_each(aLowerHead.begin(), aLowerHead.end(), [&](char& c) {return c = tolower(c);});
        string bLowerHead = b.head;
        for_each(bLowerHead.begin(), bLowerHead.end(), [&](char& c) {return c = tolower(c);});
        if (aLowerHead == bLowerHead) {
            if (a.number == b.number) {
                return a.index < b.index;
            } else {
                return a.number < b.number;
            }
        } else {
            return aLowerHead < bLowerHead;
        }
    });
    
    for (file f : convertedFiles) {
        answer.push_back(f.originName);
    }
    
    return answer;
}