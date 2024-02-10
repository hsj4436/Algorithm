#include <iostream>

#define END "end"

std::string password;

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

bool is_vowel(char ch) {
    for (int i = 0; i < 5; i++) {
        if (ch == vowels[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    while (true) {
        std::cin >> password;

        if (password == END) {
            break;
        }

        bool acceptable = true;
        bool has_vowel = false;
        for (int i = 0; i < password.size(); i++) {
            if (!has_vowel && is_vowel(password[i])) {
                has_vowel = true;
            }
            if (i + 2 < password.size()) {
                int vowel_count = 0;
                int consonant_count = 0;
                for (int j = i; j < i + 3; j++) {
                    if (is_vowel(password[j])) {
                        vowel_count++;
                    } else {
                        consonant_count++;
                    }
                }
                if (vowel_count == 3 || consonant_count == 3) {
                    acceptable = false;
                    break;
                }
            }
            if (i + 1 < password.size()) {
                if (password[i] == password[i + 1]) {
                    if (password[i] == 'e' || password[i] == 'o') {
                        continue;
                    }
                    acceptable = false;
                    break;
                }
            }
        }

        if (acceptable && has_vowel) {
            std::cout << "<" << password << "> is acceptable.\n";
        } else {
            std::cout << "<" << password << "> is not acceptable.\n";
        }
    }

    return 0;
}