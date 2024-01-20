#include <iostream>

char UCPC[4] = {'U', 'C', 'P', 'C'};

int main() {
    std::string str;
    std::getline(std::cin, str);

    int UCPC_index = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == UCPC[UCPC_index]) {
            UCPC_index++;
            if (UCPC_index == 4) {
                break;
            }
        }
    }

    if (UCPC_index == 4) {
        std::cout << "I love UCPC\n";
    } else {
        std::cout << "I hate UCPC\n";
    }

    return 0;
}
