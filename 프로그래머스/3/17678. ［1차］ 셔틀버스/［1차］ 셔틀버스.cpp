#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    sort(timetable.begin(), timetable.end());
    
    int arrivalTime = 9 * 60;
    int index = 0;
    map<int, vector<int>> buses;
    for (int i = 0; i < n; i++) {
        vector<int> bus;
        int start = index;
        for (; index < min((int)timetable.size(), start + m); index++) {
            int linedTime = stoi(timetable[index].substr(0, 2)) * 60 + stoi(timetable[index].substr(3, 2));
            if (linedTime > arrivalTime) {
                break;
            }
            bus.push_back(linedTime);
        }
        buses[arrivalTime] = bus;
        arrivalTime += t;
    }
    
    if (index == timetable.size()) {
        vector<int> lastBus = buses.rbegin()->second;
        if (lastBus.size() < m) {
            int lastTime = buses.rbegin()->first;
            answer += (to_string(lastTime / 60).size() == 1) ? "0" + to_string(lastTime / 60) : to_string(lastTime / 60);
            answer += ":";
            answer += (to_string(lastTime % 60).size() == 1) ? "0" + to_string(lastTime % 60) : to_string(lastTime % 60);
        } else {
            int lastTime = lastBus.back() - 1;
            answer += (to_string(lastTime / 60).size() == 1) ? "0" + to_string(lastTime / 60) : to_string(lastTime / 60);
            answer += ":";
            answer += (to_string(lastTime % 60).size() == 1) ? "0" + to_string(lastTime % 60) : to_string(lastTime % 60);            
        }
    } else {
        int missedTime = stoi(timetable[index].substr(0, 2)) * 60 + stoi(timetable[index].substr(3, 2));
        for (auto it = buses.rbegin(); it != buses.rend(); it++) {
            if ((*it).second.empty() || (*it).second.size() < m) {
                // 마지막 버스에 자리가 남았다면, 마지막 버스 도착 시간이 정답
                answer += (to_string((*it).first / 60).size() == 1) ? "0" + to_string((*it).first / 60) : to_string((*it).first / 60);
                answer += ":";
                answer += (to_string((*it).first % 60).size() == 1) ? "0" + to_string((*it).first % 60) : to_string((*it).first % 60);
                break;
            }
            int lastTime = *((*it).second.rbegin());
            answer += (to_string((lastTime - 1) / 60).size() == 1) ? "0" + to_string((lastTime - 1) / 60) : to_string((lastTime - 1) / 60);
            answer += ":";
            answer += (to_string((lastTime - 1) % 60).size() == 1) ? "0" + to_string((lastTime - 1) % 60) : to_string((lastTime - 1) % 60);
            break;
        }
    }
    
    return answer;
}