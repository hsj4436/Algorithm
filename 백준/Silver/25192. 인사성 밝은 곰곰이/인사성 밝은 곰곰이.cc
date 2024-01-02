#include <iostream>
#include <set>

int main() {
    int N;
    std::cin >> N;
    
    int answer = 0;
    std::set<std::string> names;
    for (int i = 0; i < N; i++) {
        std::string input;
        std::cin >> input;
        if (input == "ENTER") {
            answer += names.size();
            names.clear();
        } else {
            names.insert(input);
        }
    }
    answer += names.size();
    std::cout << answer << "\n";
    return 0;
}