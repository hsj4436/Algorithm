#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int N, M;

bool compare(std::pair<std::string, int> p1, std::pair<std::string, int> p2) {
    if (p1.second == p2.second) {
        if (p1.first.size() == p2.first.size()) {
            return p1.first < p2.first;
        }
        return p1.first.size() > p2.first.size();
    }
    return p1.second > p2.second;
}

int main() {
    std::cin >> N >> M;

    std::map<std::string, int> counts;
    for (int i = 0; i < N; i++) {
        std::string word;
        std::cin >> word;
        if (word.size() < M) {
            continue;
        }
        counts[word]++;
    }

    std::vector<std::pair<std::string, int>> dictionary;
    for (auto p : counts) {
        dictionary.push_back(p);
    }

    std::sort(dictionary.begin(), dictionary.end(), compare);

    for (auto p : dictionary) {
        std::cout << p.first << "\n";
    }

    return 0;
}
