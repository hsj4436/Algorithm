#include <iostream>
#include <vector>
#include <algorithm>

#define PII std::pair<int, int>

int N;

int main() {
    std::cin >> N;

    std::vector<PII> skyLine(N);
    std::vector<int> lastHeight;
    for (int i = 0; i < N; i++) {
        std::cin >> skyLine[i].first >> skyLine[i].second;
    }

    std::sort(skyLine.begin(), skyLine.end(), [&](PII a, PII b) {
        return a.first < b.first;
    });

    int answer = 0;
    while (!skyLine.empty()) {
        int curHeight = skyLine.back().second;
        skyLine.pop_back();

        if (lastHeight.empty()) {
            lastHeight.push_back(curHeight);
            continue;
        }
        if (curHeight > lastHeight.back()) {
            lastHeight.push_back(curHeight);
        } else if (curHeight < lastHeight.back()) {
            while (!lastHeight.empty()) {
                if (lastHeight.back() <= curHeight) {
                    break;
                }
                answer++;
                lastHeight.pop_back();
            }
            if ((lastHeight.empty() || lastHeight.back() < curHeight) && curHeight != 0) {
                lastHeight.push_back(curHeight);
            }
        }
    }

    while (!lastHeight.empty()) {
        if (lastHeight.back() != 0) {
            answer++;
        }
        lastHeight.pop_back();
    }

    std::cout << answer << "\n";

    return 0;
}
