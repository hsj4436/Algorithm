#include <iostream>
#include <vector>

int N;

int main() {
    std::cin >> N;

    std::vector<std::string> words;

    std::string word;
    std::cin >> word;
    words.push_back(word);
    for (int i = 1; i < N; i++) {
        std::cin >> word;

        bool has_same = false;
        for (auto w: words) {
            if (w.size() != word.size()) {
                continue;
            }

            for (int j = 0; j < w.size(); j++) {
                bool from_here = true;
                for (int k = 0; k < w.size(); k++) {
                    if (w[(j + k) % w.size()] != word[k]) {
                        from_here = false;
                        break;
                    }
                }
                if (from_here) {
                    has_same = true;
                    break;
                }
            }
        }
        if (!has_same) {
            words.push_back(word);
        }
    }

    std::cout << words.size() << "\n";

    return 0;
}
