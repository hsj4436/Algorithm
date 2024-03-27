#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int N = prices.size();
    for (int i = 0; i < N; i++) {
        int index = N - 1;
        for (int j = i + 1; j < N; j++) {
            if (prices[j] < prices[i]) {
                index = j;
                break;
            }
        }
        answer.push_back(index - i);
    }
    return answer;
}