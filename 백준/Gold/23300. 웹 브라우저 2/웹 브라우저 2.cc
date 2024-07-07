#include <iostream>
#include <queue>

int N, Q;

int main() {
    std::cin >> N >> Q;

    std::deque<std::pair<int, int>> backward, forward;
    std::string command;
    int currentPage = 0, pageNumber = 0;
    while (Q--) {
        std::cin >> command;
        if (command == "B") {
            if (backward.empty()) {
                continue;
            }
            if (forward.empty()) {
                forward.push_front({currentPage, 1});
            } else if (forward.front().first == currentPage) {
                forward.front().second++;
            } else {
                forward.push_front({currentPage, 1});
            }
            currentPage = backward.back().first;
            backward.back().second--;
            if (backward.back().second == 0) {
                backward.pop_back();
            }
        } else if (command == "F") {
            if (forward.empty()) {
                continue;
            }
            if (backward.empty()) {
                backward.push_back({currentPage, 1});
            } else if (backward.back().first == currentPage) {
                backward.back().second++;
            } else {
                backward.push_back({currentPage, 1});
            }
            currentPage = forward.front().first;
            forward.front().second--;
            if (forward.front().second == 0) {
                forward.pop_front();
            }
        } else if (command == "A") {
            std::cin >> pageNumber;
            forward.clear();
            if (currentPage != 0) {
                if (backward.empty()) {
                    backward.push_back({currentPage, 1});
                } else if (backward.back().first == currentPage) {
                    backward.back().second++;
                } else {
                    backward.push_back({currentPage , 1});
                }
            }
            currentPage = pageNumber;
        } else if (command == "C") {
            std::deque<std::pair<int, int>> backwardTemp;
            while (!backward.empty()) {
                std::pair<int, int> info = backward.front();
                backward.pop_front();
                info.second = 1;
                backwardTemp.push_back(info);
            }
            while (!backwardTemp.empty()) {
                backward.push_back(backwardTemp.front());
                backwardTemp.pop_front();
            }
        }
    }

    std::cout << currentPage << "\n";
    if (backward.empty()) {
        std::cout << "-1\n";
    } else {
        while (!backward.empty()) {
            std::pair<int, int> info = backward.back();
            backward.pop_back();
            for (int i = 0; i < info.second; i++) {
                std::cout << info.first << " ";
            }
        }
        std::cout << "\n";
    }
    if (forward.empty()) {
        std::cout << "-1\n";
    } else {
        while (!forward.empty()) {
            std::pair<int, int> info = forward.front();
            forward.pop_front();
            for (int i = 0; i < info.second; i++) {
                std::cout << info.first << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
