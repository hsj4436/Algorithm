#include <string>
#include <vector>

using namespace std;

vector<vector<int>> user;
vector<int> emoticon;
vector<int> discountRate;
int maxPlusUsers = 0;
int maxProfit = 0;

void sol(int index) {
    if (index == emoticon.size()) {
        int plusUsers = 0;
        int profit = 0;
        for (vector<int> v : user) {
            int cost = 0;
            for (int i = 0; i < emoticon.size(); i++) {
                if (discountRate[i] >= v[0]) {
                    cost += emoticon[i] * (100 - discountRate[i]) / 100;
                }
            }
            if (cost >= v[1]) {
                plusUsers++;
            } else {
                profit += cost;
            }
        }
        if (plusUsers > maxPlusUsers) {
            maxPlusUsers = plusUsers;
            maxProfit = profit;
        } else if (plusUsers == maxPlusUsers && profit > maxProfit) {
            maxProfit = profit;
        }
        return;
    }
    
    for (int i = 1; i < 5; i++) {
        discountRate[index] = i * 10;
        sol(index + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    user = users;
    emoticon = emoticons;
    for (int i = 0; i < emoticon.size(); i++) {
        discountRate.push_back(0);
    }
    
    sol(0);
    
    answer.push_back(maxPlusUsers);
    answer.push_back(maxProfit);
    
    return answer;
}