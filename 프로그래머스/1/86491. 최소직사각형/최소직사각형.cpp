#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxW = 0, maxH = 0;
    for (vector<int> p : sizes) {
        if (max(maxW, p[0]) * max(maxH, p[1]) < max(maxW, p[1]) * max(maxH, p[0])) {
            maxW = max(maxW, p[0]);
            maxH = max(maxH, p[1]);
        } else {
            maxW = max(maxW, p[1]);
            maxH = max(maxH, p[0]);
        }
    }
    answer = maxW * maxH;
    return answer;
}