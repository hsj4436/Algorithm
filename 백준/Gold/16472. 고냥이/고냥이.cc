#include <iostream>

int N;
std::string input;
int alphabet[27];

int main() {
    std::cin >> N >> input;

    int answer = 1;
    int count = 1;
    alphabet[input[0] - 'a']++;
    int left = 0, right = 0;
    while (true) {
        if (count < N) {
            if (right == input.size() - 1) {
                if (left == input.size() - 1) {
                    break;
                }
                alphabet[input[left] - 'a']--;
                if (alphabet[input[left] - 'a'] == 0) {
                    count--;
                }
                answer = std::max(answer, right - left + 1);
                left++;
            } else {
                right++;
                if (alphabet[input[right] - 'a'] == 0) {
                    count++;
                }
                alphabet[input[right] - 'a']++;
            }
        } else if (count == N) {
            if (right == input.size() - 1) {
                if (left == input.size() - 1) {
                    break;
                }
                alphabet[input[left] - 'a']--;
                if (alphabet[input[left] - 'a'] == 0) {
                    count--;
                }
                answer = std::max(answer, right - left + 1);
                left++;
            } else {
                right++;
                if (alphabet[input[right] - 'a'] == 0) {
                    answer = std::max(answer, right - left);
                    alphabet[input[right] - 'a']++;
                    count++;
                    while (count > N) {
                        alphabet[input[left] - 'a']--;
                        if (alphabet[input[left] - 'a'] == 0) {
                            count--;
                        }
                        left++;
                    }
                } else {
                    alphabet[input[right] - 'a']++;
                }
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}
