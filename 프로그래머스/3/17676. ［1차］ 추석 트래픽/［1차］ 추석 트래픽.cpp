#include <string>
#include <vector>

using namespace std;

vector<int> startTime;
vector<int> endTime;

int solution(vector<string> lines) {
    int answer = 0;
    
    for (string &line : lines) {
        line.pop_back();
        int hour = stoi(line.substr(11, 2));
        int minute = stoi(line.substr(14, 2));
        int second = stoi(line.substr(17, 2));
        int milli = stoi(line.substr(20, 3));
        
        int responseTime = hour * 60 * 60 * 1000 + minute * 60 * 1000 + second * 1000 + milli;
        string task = line.substr(24);
        int taskTime = (int)(stof(task) * 1000);
        int requestTime = responseTime - taskTime + 1;
        
        startTime.push_back(requestTime);
        endTime.push_back(responseTime);
    }
    
    for (int i = 0; i < lines.size(); i++) {
        int count = 0;
        for (int j = i; j < lines.size(); j++) {
            if (startTime[j] < endTime[i] + 1000) {
                count++;
            }
        }
        answer = max(answer, count);
    }
    
    return answer;
}