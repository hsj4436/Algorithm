#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> nameToIndex;
int profit[10001];
int parent[10001];

void distributeTax(int index, int tax) {
    int next = parent[index];
    if (next == -1) {
        return;
    }
    int newTax = tax / 10;
    profit[index] += tax - newTax;

    if (newTax < 1) {
        return;
    }
    distributeTax(next, newTax);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    enroll.insert(enroll.begin(), "CENTER");
    referral.insert(referral.begin(), "X");
    for (int i = 0; i < enroll.size(); i++) {
        nameToIndex[enroll[i]] = i;
    }
    for (int i = 0; i < referral.size(); i++) {
        if (referral[i] == "X") {
            parent[i] = -1;
        } else if (referral[i] == "-") {
            parent[i] = 0;
        } else {
            parent[i] = nameToIndex[referral[i]];
        }
    }
    for (int i = 0; i < seller.size(); i++) {
        // profit[nameToIndex[seller[i]]] = amount[i] * 100;
        distributeTax(nameToIndex[seller[i]], amount[i] * 100);
    }
    
    for (int i = 1; i < enroll.size(); i++) {
        answer.push_back(profit[i]);
    }
    
    return answer;
}