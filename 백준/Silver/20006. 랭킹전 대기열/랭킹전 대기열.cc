#include <iostream>
#include <vector>
#include <algorithm>

int P, M;
bool isReady[301];
int baseLevel[301];
std::vector<std::vector<std::pair<int, std::string>>> rooms;

int main() {
    std::cin >> P >> M;

    std::string name;
    int L;
    for (int i = 0; i < P; i++) {
        std::cin >> L >> name;
        bool entered = false;
        for (int j = 0; j < rooms.size(); j++) {
            if (!isReady[j] && baseLevel[j] - 10 <= L && L <= baseLevel[j] + 10) {
                rooms[j].push_back({L, name});
                if (rooms[j].size() == M) {
                    isReady[j] = true;
                }
                entered = true;
                break;
            }
        }
        if (!entered) {
            rooms.push_back(std::vector<std::pair<int, std::string>>(1, {L, name}));
            baseLevel[rooms.size() - 1] = L;
            if (rooms[rooms.size() - 1].size() == M) {
                isReady[rooms.size() - 1] = true;
            }
        }
    }

    for (int i = 0; i < rooms.size(); i++) {
        if (isReady[i]) {
            std::cout << "Started!\n";
        } else {
            std::cout << "Waiting!\n";
        }
        std::sort(rooms[i].begin(), rooms[i].end(), [&](std::pair<int, std::string> a, std::pair<int, std::string> b) {
            return a.second < b.second;
        });
        for (auto p : rooms[i]) {
            std::cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}
