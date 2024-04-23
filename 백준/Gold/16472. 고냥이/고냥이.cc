#include <iostream>

int N;
std::string input;
int alphabet[27];

int main() {
    std::cin >> N >> input;

    int answer = 0;
    int count = 0;
    int left = 0, right = 0;
    for (; right < input.size(); right++) {
        if (count < N) {
            if (alphabet[input[right] - 'a'] == 0) {
                count++;
            }
            alphabet[input[right] - 'a']++;
            answer = std::max(answer, right - left + 1);
        } else if (count == N) {
            if (alphabet[input[right] - 'a'] == 0) {
                count++;
                alphabet[input[right] - 'a']++;
                while (count > N) {
                    alphabet[input[left] - 'a']--;
                    if (alphabet[input[left] - 'a'] == 0) {
                        count--;
                    }
                    left++;
                }
                answer = std::max(answer, right - left + 1);
            } else {
                alphabet[input[right] - 'a']++;
                answer = std::max(answer, right - left + 1);
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}
