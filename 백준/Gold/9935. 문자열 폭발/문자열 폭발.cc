#include <iostream>
#include <queue>
#include <stack>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::deque<char> explodeQ;
    std::stack<int> indexTrace;

    char input[1000001];
    std::string str;
    std::cin >> str;
    for (int i = 0; i < str.size(); i++) {
        input[i] = str[i];
    }

    std::string explode = "";
    std::cin >> explode;

    int explodeIndex = 0;
    for (int i = 0; i < str.size(); i++) {
        explodeQ.push_back(input[i]);
        if (input[i] == explode[explodeIndex]) {
            explodeIndex++;
        } else {
            indexTrace.push(explodeIndex);
            explodeIndex = 0;
            if (input[i] == explode[explodeIndex]) {
                explodeIndex++;
            } else {
//                indexTrace.pop();
                while (!indexTrace.empty()) {
                    indexTrace.pop();
                }
            }
        }
        if (explodeIndex == explode.size()) {
            for (int j = 0; j < explodeIndex; j++) {
                explodeQ.pop_back();
            }
            if (!indexTrace.empty()) {
                explodeIndex = indexTrace.top();
                indexTrace.pop();
            } else {
                explodeIndex = 0;
            }
        }
    }

    if (explodeQ.empty()) {
        std::cout << "FRULA\n";
    } else {
        while (!explodeQ.empty()) {
            std::cout << explodeQ.front();
            explodeQ.pop_front();
        }
        std::cout << "\n";
    }

    return 0;
}
