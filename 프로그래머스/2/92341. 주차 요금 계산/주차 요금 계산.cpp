#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

int baseTime, baseFee, unitTime, unitFee;
map<string, int> parkRecord;
map<string, int> accumulatedTime;
map<string, int> parkFee;

int toMinute(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3));
    return hour * 60 + minute;
}

int calculateFee(int &minutes) {
    int totalFee = 0;
    if (minutes <= baseTime) {
        return baseFee;
    } else {
        totalFee = baseFee;
        minutes -= baseTime;
    }
    if (minutes % unitTime == 0) {
        totalFee += unitFee * (minutes / unitTime);
    } else {
        totalFee += unitFee * ((minutes / unitTime) + 1);
    }
    return totalFee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    baseTime = fees[0], baseFee = fees[1], unitTime = fees[2], unitFee = fees[3];
    
    for (string record : records) {
        stringstream ss(record);
        string time, carNumber, info;
        ss >> time >> carNumber >> info;
        
        int minute = toMinute(time);
        if (info == "IN") {
            parkRecord[carNumber] = minute;
        } else {
            accumulatedTime[carNumber] += minute - parkRecord[carNumber];
            parkRecord[carNumber] = -1;
        }
    }
    
    for (auto p : parkRecord) {
        if (p.second != -1) {
            accumulatedTime[p.first] += 23 * 60 + 59 - p.second;            
        }
    }
    
    for (auto &p : accumulatedTime) {
        parkFee[p.first] = calculateFee(p.second);
    }
    
    vector<pair<string, int>> parkFeeVector(parkFee.begin(), parkFee.end());
    sort(parkFeeVector.begin(), parkFeeVector.end(), [&](pair<string, int> a, pair<string, int> b) {
        return a.first < b.first; 
    });
    
    for (auto p : parkFeeVector) {
        answer.push_back(p.second);
    }
    
    return answer;
}