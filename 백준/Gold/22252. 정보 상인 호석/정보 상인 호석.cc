#include <iostream>
#include <map>
#include <queue>

int Q;
std::map<std::string, std::priority_queue<long>> info;

int main() {
    std::cin >> Q;

    long answer = 0;
    int command, items;
    std::string name;
    for (int i = 0; i < Q; i++) {
        std::cin >> command >> name >> items;
        if (command == 1) {
            int c;
            for (int j = 0; j < items; j++) {
                std::cin >> c;
                info[name].push(c);
            }
        } else {
            long count = 0;
            while (count != items && !info[name].empty()) {
                answer += info[name].top();
                info[name].pop();
                count++;
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}
