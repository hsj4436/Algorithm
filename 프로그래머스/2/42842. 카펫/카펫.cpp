#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int height = 1;
    while (height != yellow + 1) {
        if (yellow % height == 0) {
            int width = yellow / height;
            int requiredBrown = height * 2 + (width + 2) * 2;
            if (requiredBrown == brown) {
                answer.push_back(width + 2);
                answer.push_back(height + 2);
                break;
            }
        }
        height++;
    }
    return answer;
}