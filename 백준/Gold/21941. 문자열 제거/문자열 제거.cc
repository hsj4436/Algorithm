#include <iostream>
#include <algorithm>

#define PSI std::pair<std::string, int>

std::string S;
int M;
PSI ax[101];

int main() {
    std::cin >> S >> M;

    for (int i = 0; i < M; i++) {
        std::cin >> ax[i].first >> ax[i].second;
    }

    std::sort(ax, ax + M, [&](PSI a, PSI b) {
        if (a.second / a.first.size() == b.second / b.first.size()) {
            return a.first.size() < b.first.size();
        } else {
            return a.second / a.first.size() > b.second / b.first.size();
        }
    });

    int score = 0;
    while (true) {
        bool replaced = false;
        for (int i = 0; i < M; i++) {
            if (ax[i].second < ax[i].first.size()) {
                continue;
            }
            auto it = S.find(ax[i].first);
            if (it != std::string::npos) {
                score += ax[i].second;
                S.replace(it, ax[i].first.size(), "_");
                replaced = true;
                break;
            }
        }
        if (!replaced) {
            break;
        }
    }

    for (int i = 0; i < S.size(); i++) {
        if (S[i] != '_') {
            score++;
        }
    }

    std::cout << score << "\n";

    return 0;
}
