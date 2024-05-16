#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 101;
int weakSize = 0;
bool checked[31];
vector<int> weaks;
vector<int> dists;

void sol(int friendIndex, int checkedWeaks) {
    if (checkedWeaks == weakSize) {
        answer = min(answer, friendIndex);
        return;
    }
    if (friendIndex == dists.size() || friendIndex >= answer) {
        return;
    }
    
    for (int i = 0; i < weakSize; i++) {
        if (checked[i]) {
            continue;
        }
        int endIndex = i;
        for (int j = i; j < weaks.size(); j++) {
            if (checked[j]) {
                break;
            }
            if (weaks[j] - weaks[i] > dists[friendIndex]) {
                break;
            } else {
                endIndex = j;
            }
        }
        for (int k = i; k <= endIndex; k++) {
            checked[k] = true;
            if (k - weakSize >= 0) {
                checked[k - weakSize] = true;
            }
            if (k + weakSize < weaks.size()) {
                checked[k + weakSize] = true;
            }
        }
        sol(friendIndex + 1, checkedWeaks + endIndex - i + 1);
        for (int k = i; k <= endIndex; k++) {
            checked[k] = false;
            if (k - weakSize >= 0) {
                checked[k - weakSize] = false;
            }
            if (k + weakSize < weaks.size()) {
                checked[k + weakSize] = false;
            }
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    weaks = weak;
    dists = dist;
    sort(dists.begin(), dists.end(), greater<int>());
    
    weakSize = weak.size();
    for (int i = 0; i < weakSize; i++) {
        weaks.push_back(weak[i] + n);
    }
    
    sol(0, 0);
    
    if (answer == 101) {
        answer = -1;
    }
    
    return answer;
}