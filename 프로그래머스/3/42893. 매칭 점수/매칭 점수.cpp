#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int basicScores[21];     // 기본점수
int externalScores[21];  // 외부 링크 수
double linkScores[21];      // 링크점수
map<string, int> mapping;
map<int, vector<string>> links;
vector<int> graph[21];

int solution(string word, vector<string> pages) {
    int answer = 0;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    for (int i = 0; i < pages.size(); i++) {
        vector<string> externalLinks;
        int basicScore = 0;
        string url;
        if (pages[i].find("<meta property=\"og:url\" content=") != string::npos) {
            auto index = pages[i].find("https", pages[i].find("<meta property=\"og:url\" content="));
            for (; index != pages.size(); index++) {
                if (pages[i][index] == '\"') {
                    break;
                }
                url.push_back(pages[i][index]);
            }
            mapping[url] = i;
        }
        int link_index = 0;
        while (true) {
            link_index = pages[i].find("<a href=", link_index + 1);
            if (link_index == string::npos) {
                break;
            }
            string link;
            auto index = pages[i].find("https", link_index);
            for (; index != pages[i].size(); index++) {
                if (pages[i][index] == '\"') {
                    break;
                }
                link.push_back(pages[i][index]);
            }
            externalLinks.push_back(link);
        }

        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);
        int wordCount = 0;
        if (pages[i].size() < word.size()) {
            continue;
        } else if (pages[i].size() == word.size()) {
            if (pages[i] == word) {
                basicScore++;
                continue;
            }
        } else if (pages[i].size() > word.size()) {
            if ((pages[i][word.size()] < 'a' || pages[i][word.size()] > 'z') && pages[i].substr(0, word.size()) == word) {
                basicScore++;
            }
            if ((pages[i][pages[i].size() - word.size() - 1] < 'a' || pages[i][pages[i].size() - word.size() - 1] > 'a') && pages[i].substr(pages[i].size() - word.size(), word.size()) == word) {
                basicScore++;
            }
        }
        for (int j = 1; j < pages[i].size() - word.size(); j++) {
            if ((pages[i][j - 1] < 'a' || pages[i][j - 1] > 'z') && (pages[i][j + word.size()] < 'a' || pages[i][j + word.size()] > 'z')) {
                if (pages[i].substr(j, word.size()) == word) {
                    wordCount++;
                    j += word.size() - 1;
                }
            }
        }
        basicScore += wordCount;
        
        links[i] = externalLinks;
        basicScores[i] = basicScore;
        externalScores[i] = externalLinks.size();
    }
    
    for (int i = 0; i < pages.size(); i++) {
        for (string url : links[i]) {
            if (mapping.find(url) != mapping.end()) {
                int index = mapping[url];
                graph[i].push_back(index);
            }
        }
    }
    
    for (int i = 0; i < pages.size(); i++) {
        for (int next : graph[i]) {
            if (externalScores[i] == 0) {
                continue;
            }
            linkScores[next] += (double)basicScores[i] / (double)externalScores[i];
        }
    }
    
    vector<pair<double, int>> finalScores;
    for (int i = 0; i < pages.size(); i++) {
        finalScores.push_back({(double)basicScores[i] + linkScores[i], i});
    }
    
    sort(finalScores.begin(), finalScores.end(), [&](pair<double, int> a, pair<double, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first > b.first;
        }
    });
    
    answer = finalScores[0].second;
    
    return answer;
}