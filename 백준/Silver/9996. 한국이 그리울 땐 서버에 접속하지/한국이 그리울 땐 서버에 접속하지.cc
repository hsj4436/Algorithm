#include <iostream>

int N;

int main() {
    std::cin >> N;

    std::string pattern;
    std::cin >> pattern;

    int index = pattern.find('*');
    std::string prefix = pattern.substr(0, index);
    std::string suffix = pattern.substr(index + 1);

    for (int i = 0; i < N; i++) {
        std::string file;
        std::cin >> file;

        if (file.size() < prefix.size() + suffix.size()) {
            std::cout << "NE\n";
            continue;
        }

        bool matched = true;
        for (int j = 0; j < prefix.size(); j++) {
            if (file[j] != prefix[j]) {
                matched = false;
                break;
            }
        }

        if (!matched) {
            std::cout << "NE\n";
            continue;
        }

        for (int j = 0; j < suffix.size(); j++) {
            if (file[file.size() - suffix.size() + j] != suffix[j]) {
                matched = false;
                break;
            }
        }

        if (!matched) {
            std::cout << "NE\n";
        } else {
            std::cout << "DA\n";
        }
    }
    return 0;
}
