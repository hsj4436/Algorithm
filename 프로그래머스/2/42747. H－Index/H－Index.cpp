#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    for (int i = 0; i < max((int)citations.size() + 1, *(citations.rbegin()) + 1); i++) {
        if (citations.end() - lower_bound(citations.begin(), citations.end(), i) >= i) {
            answer = i;
        }
    }
    return answer;
}