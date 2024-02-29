#include <iostream>
#include <vector>
#include <map>

int nA, nB;
std::map<int, int> m;

int main() {
    std::cin >> nA >> nB;

    int number;
    for (int i = 0; i < nA; i++) {
        std::cin >> number;
        m[number] -= 1;
    }
    for (int i = 0; i < nB; i++) {
        std::cin >> number;
        m[number] += 1;
    }

    std::vector<int> answer;
    for (auto p : m) {
        if (p.second < 0) {
            answer.push_back(p.first);
        }
    }

    if (answer.empty()) {
        std::cout << "0\n";
    } else {
        std::cout << answer.size() << "\n";
        for (int i : answer) {
            std::cout << i << " ";
        }
    }

    return 0;
}
