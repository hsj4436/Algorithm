#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if (cacheSize == 0) {
        return cities.size() * 5;
    }
    map<string, int> cache;
    for (int i = 0; i < cities.size(); i++) {
        string cityName = cities[i];
        for (auto &ch : cityName) {
            ch = tolower(ch);
        }
        if (cache.find(cityName) != cache.end()) {
            answer++;
            cache[cityName] = i;
        } else {
            answer += 5;
            if (cache.size() < cacheSize) {
                cache[cityName] = i;
                continue;
            }
            vector<pair<string, int>> cacheVector(cache.begin(), cache.end());
            sort(cacheVector.begin(), cacheVector.end(), [&](pair<string, int> a, pair<string, int> b) {
                return a.second < b.second;
            });
            cache.erase(cacheVector[0].first);
            cache[cityName] = i;
        }
    }
    return answer;
}