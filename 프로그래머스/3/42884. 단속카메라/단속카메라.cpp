#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), [&](vector<int> a, vector<int> b) {
       if (a[1] == b[1]) {
           return a[0] < b[0];
       } else {
           return a[1] < b[1];
       }
    });
    
    int frontEnd = routes[0][1];
    for (int i = 1; i < routes.size(); i++) {
        if (routes[i][0] > frontEnd) {
            answer++;
            frontEnd = routes[i][1];
        }
    }
    answer++;
    return answer;
}