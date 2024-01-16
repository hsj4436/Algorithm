#include <iostream>
#include <set>
#include <map>

int N;
int fruits[200001];

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> fruits[i];
    }

    int answer = 0;
    int left = 1, right = 2;
    std::map<int, int> type_count;
    std::set<int> types;
    type_count[fruits[1]] = 1;
    types.insert(fruits[1]);
    while (left < right) {
        if (types.size() <= 2) {
            answer = std::max(answer, right - left);
            if (right == N + 1) {
                type_count[fruits[left]]--;
                if (type_count[fruits[left]] == 0) {
                    types.erase(fruits[left]);
                }
                left++;
            } else {
                type_count[fruits[right]]++;
                if (type_count[fruits[right]] == 1) {
                    types.insert(fruits[right]);
                }
                right++;
            }
        } else {
            type_count[fruits[left]]--;
            if (type_count[fruits[left]] == 0) {
                types.erase(fruits[left]);
            }
            left++;
        }
    }

    std::cout << answer << "\n";

    return 0;
}
