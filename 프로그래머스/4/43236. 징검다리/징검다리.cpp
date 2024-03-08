#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    if (n == rocks.size()) {
        return distance;
    }
    
    sort(rocks.begin(), rocks.end());

    int left = 0, right = distance;
    while (left <= right) {
        int mid = (left + right) / 2;
        
        int erased = 0;
        int previousPosition = 0;
        for (int i = 0; i < rocks.size(); i++) {
            if (rocks[i] - previousPosition < mid) {
                erased++;
            } else {
                previousPosition = rocks[i];
            }
        }
        if (distance - previousPosition < mid) {
            erased++;
        }
        if (erased <= n) {
            answer = max(answer, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return answer;
}
