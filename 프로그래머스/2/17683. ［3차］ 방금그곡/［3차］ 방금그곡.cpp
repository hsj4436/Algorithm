#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>

using namespace std;

string n[6] = {"A#", "B#", "C#", "D#", "F#", "G#"};
string c[6] = {"a", "b", "c", "d", "f", "g"};

struct music {
    int index;
    int start;
    int end;
    string title;
    string notes;
    music() {}
    music(int index, int start, int end, string title, string notes) {
        this->index = index;
        this->start = start;
        this-> end = end;
        this-> title = title;
        this->notes = notes;
    }
};

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    
    for (int j = 0; j < 6; j++) {
        m = regex_replace(m, regex(n[j]), c[j]);
    }
    
    vector<music> musics;
    for (int i = 0; i < musicinfos.size(); i++) {
        stringstream ss(musicinfos[i]);
        string startTime, endTime, title, noteString;
        getline(ss, startTime, ',');
        getline(ss, endTime, ',');
        getline(ss, title, ',');
        getline(ss, noteString, ',');
        
        int start = stoi(startTime.substr(0, 2)) * 60 + stoi(startTime.substr(3, 2));
        int end = stoi(endTime.substr(0, 2)) * 60 + stoi(endTime.substr(3, 2));
        string notes;
        for (int j = 0; j < 6; j++) {
            noteString = regex_replace(noteString, regex(n[j]), c[j]);
        }
        int noteIndex = 0;
        for (int j = start; j < end; j++) {
            notes.push_back(noteString[noteIndex]);
            noteIndex++;
            noteIndex %= noteString.size();            
        }
        
        musics.push_back(music(i, start, end, title, notes));
    }
    
    sort(musics.begin(), musics.end(), [&](music a, music b) {
       if (a.end - a.start == b.end - b.start) {
           return a.index < b.index;
       } else {
           return (a.end - a.start) > (b.end - b.start);
       }
    });
    
    for (music ms : musics) {
        int index = ms.notes.find(m);
        if (index == string::npos) {
            continue;
        }
        if (index + m.size() < ms.notes.size() && ms.notes[index + m.size()] == '#') {
            continue;
        }
        answer = ms.title;
        break;
    }
    
    return answer;
}