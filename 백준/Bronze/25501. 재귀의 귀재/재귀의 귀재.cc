#include <iostream>

int T;

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> T;

    for (int i = 0; i < T; i++) {
        std::string S;
        std::cin >> S;
        int left = 0, right = S.size() - 1;
        int answer = 1, cnt = 1;
        while (left < right) {
            if (S[left] == S[right]) {
                left++;
                right--;
                cnt++;
            } else {
                answer = 0;
                break;
            }
        }
        std::cout << answer << " " << cnt << "\n";
    }
    return 0;
}
