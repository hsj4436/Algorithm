#include <string>
#include <vector>

#define LL long long

using namespace std;

LL playTime;
LL advTime;
LL viewerCount[360001];

LL getSeconds(string t) {
    return stoll(t.substr(0, 2)) * 60 * 60 + stoll(t.substr(3, 2)) * 60 + stoll(t.substr(6));
}

string getStringTime(LL t) {
    LL hour = t / 3600;
    t %= 3600;
    LL minute = t / 60;
    t %= 60;
    LL second = t;
    string ret;
    ret += ((hour < 10) ? "0" + to_string(hour) : to_string(hour)) + ":";
    ret += ((minute < 10) ? "0" + to_string(minute) : to_string(minute)) + ":";
    ret += (second < 10) ? "0" + to_string(second) : to_string(second);
    
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    playTime = getSeconds(play_time);
    advTime = getSeconds(adv_time);
    
    for (string log : logs) {
        LL start = getSeconds(log.substr(0, 8));
        LL end = getSeconds(log.substr(9));
        viewerCount[start]++;
        viewerCount[end]--;
    }
    
    LL viewersInWindow = viewerCount[0];
    for (int i = 1; i < playTime + 1; i++) {
        viewerCount[i] += viewerCount[i - 1];
        if (i < advTime) {
            viewersInWindow += viewerCount[i];
        }
    }
    
    LL maxViewers = viewersInWindow;
    LL maxStartTime = 0;
    for (int i = advTime; i < playTime + 1; i++) {
        viewersInWindow -= viewerCount[i - advTime];
        viewersInWindow += viewerCount[i];
        
        if (viewersInWindow > maxViewers) {
            maxViewers = viewersInWindow;
            maxStartTime = i - advTime + 1;
        }
    }
    
    answer = getStringTime(maxStartTime);
    
    return answer;
}