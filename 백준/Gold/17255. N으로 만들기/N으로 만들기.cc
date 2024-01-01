#include <iostream>

std::string N;
int answer = 0;

void back_track(std::string current) {
    if (current == N) {
        answer++;
        return;
    }

    for (int i = 0; i < 10; i++) {
        std::string left = current;
        std::string right = current;
        left.insert(left.begin(), i + '0');
        right.push_back(i + '0');
        if (N.find(left) != std::string::npos) {
            back_track(left);
        }
        if (left == right || current.size() == 0) {
            continue;
        }
        if (N.find(right) != std::string::npos) {
            back_track(right);
        }
    }
}

int main() {
    std::cin >> N;

    back_track("");

    std::cout << answer << "\n";
    return 0;
}
