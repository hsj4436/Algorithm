#include <string>
#include <vector>
#include <limits.h>

#define LL long long

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = LLONG_MAX / 2;
    LL left = 0, right = 100000001L * n;
    while (left <= right) {
        LL mid = (left + right) / 2;
        LL passedPerson = 0;
        for (int t : times) {
            passedPerson += mid / t;
        }
        if (passedPerson >= n) {
            right = mid - 1;
            answer = min(answer, mid);
        } else {
            left = mid + 1;
        }
    }
    return answer;
}