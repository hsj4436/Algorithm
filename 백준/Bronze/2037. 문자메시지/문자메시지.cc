#include <iostream>
#include <vector>
#include <map>

int P, W;
std::map<int, std::vector<char>> keypad;
std::string text;

std::pair<int, int> find_button(char ch) {
    for (auto p : keypad) {
        for (int i = 0; i < p.second.size(); i++) {
            if (p.second[i] == ch) {
                return {p.first, i};
            }
        }
    }
}

int main() {
    keypad[1].push_back(' ');
    keypad[2] = {'A', 'B', 'C'};
    keypad[3] = {'D', 'E', 'F'};
    keypad[4] = {'G', 'H', 'I'};
    keypad[5] = {'J', 'K', 'L'};
    keypad[6] = {'M', 'N', 'O'};
    keypad[7] = {'P', 'Q', 'R', 'S'};
    keypad[8] = {'T', 'U', 'V'};
    keypad[9] = {'W', 'X', 'Y', 'Z'};

    std::cin >> P >> W;
    std::cin.ignore();
    std::getline(std::cin, text);

    int answer = 0;
    std::pair<int, int> b = find_button(text[0]);
    answer += (b.second + 1) * P;
    for (int i = 1; i < text.size(); i++) {
        std::pair<int, int> b1 = find_button(text[i - 1]);
        std::pair<int, int> b2 = find_button(text[i]);
        if (b1.first == b2.first && b1.first != 1 && b2.first != 1) {
            answer += W;
            answer += (b2.second + 1) * P;
        } else {
            answer += (b2.second + 1) * P;
        }
    }

    std::cout << answer << "\n";
    return 0;
}
