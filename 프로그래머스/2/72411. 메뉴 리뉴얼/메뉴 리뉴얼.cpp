#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> courseSize;
map<string, int> courses;

void makeCourse(string& order, int index, string newCourse) {
    for (int size : courseSize) {
        if (newCourse.size() == size) {
            courses[newCourse]++;
        }
    }
    
    if (index == order.size()) {
        return;
    }
    
    for (int i = index; i < order.size(); i++) {
        newCourse.push_back(order[i]);
        makeCourse(order, i + 1, newCourse);
        newCourse.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    courseSize = course;
    
    for (string& order : orders) {
        sort(order.begin(), order.end());
        makeCourse(order, 0, "");
    }
    
    for (int size : courseSize) {
        vector<string> v;
        int maxOrderCount = 2;
        for (auto p : courses) {
            if (p.first.size() == size) {
                if (p.second > maxOrderCount) {
                    maxOrderCount = p.second;
                    v.clear();
                    v.push_back(p.first);
                } else if (p.second == maxOrderCount) {
                    v.push_back(p.first);
                }
            }
        }
        answer.insert(answer.end(), v.begin(), v.end());
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}