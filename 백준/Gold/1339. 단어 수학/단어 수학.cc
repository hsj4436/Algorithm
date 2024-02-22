#include <iostream>
#include <vector>
#include <algorithm>

int N;
long long alphabet[26];

bool cmp(std::pair<char, long long> a, std::pair<char, long long> b) {
    return a.second > b.second;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::string word;
        std::cin >> word;
        long long size = 1;
        for (int j = word.size() - 1; j > -1; j--) {
            alphabet[word[j] - 'A'] += size;
            size *= 10;
        }
    }

    std::vector<std::pair<char, long long>> vec;
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] != 0) {
            vec.push_back({(char)(i + 'A'), alphabet[i]});
        }
    }

    std::sort(vec.begin(), vec.end(), cmp);

    long long ans = 0;
    int num = 9;
    for (auto p : vec) {
        ans += p.second * num;
        num--;
    }

    std::cout << ans << "\n";

    return 0;
}
