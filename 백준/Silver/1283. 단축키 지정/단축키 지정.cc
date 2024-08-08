#include <iostream>
#include <map>
#include <sstream>

int N;
std::string options[31];
std::map<char, bool> command;

int main() {
    std::cin >> N;

    std::cin.ignore();

    std::string option;
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, option);

        std::istringstream iss(option);
        std::string token;
        std::string candidateToken;
        char candidate;
        int candidateIndex = -1;
        bool assigned = false;
        while (std::getline(iss, token, ' ')) {
            for (int j = 0; j < token.size(); j++) {
                if (j == 0 && !command[std::tolower(token[j])]) {
                    command[std::tolower(token[j])] = true;
                    assigned = true;
                    int startIndex = option.find(token);
                    option.insert( startIndex + j, "[");
                    option.insert(startIndex + j + 2, "]");
                    break;
                }
                if (candidateIndex == -1 && !command[std::tolower(token[j])]) {
                    candidateToken = token;
                    candidate = token[j];
                    candidateIndex = j;
                }
            }
            if (assigned) {
                break;
            }
        }
        if (!assigned && candidateIndex != -1) {
            int startIndex = option.find(candidateToken);
            option.insert( startIndex + candidateIndex, "[");
            option.insert(startIndex + candidateIndex + 2, "]");
            command[std::tolower(candidate)] = true;
        }
        options[i] = option;
    }

    for (int i = 0; i < N; i++) {
        std::cout << options[i] << "\n";
    }
    return 0;
}
