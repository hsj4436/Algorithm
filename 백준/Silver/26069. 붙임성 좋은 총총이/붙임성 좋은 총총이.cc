#include <iostream>
#include <set>

int main() {
    int N;
    std::cin >> N;
    std::set<std::string> names;
    names.insert("ChongChong");
    
    int answer = 1;
    std::string name;
    for (int i = 0; i < N; i++) {
        std::string a, b;
        std::cin >> a >> b;
        if (names.find(a) != names.end()) {
            if (names.find(b) == names.end()) {
                names.insert(b);
                answer++;    
            }
        } else if (names.find(b) != names.end()) {
            if (names.find(a) == names.end()) {
                names.insert(a);
                answer++;    
            }
        }
    }
    
    std::cout << answer << "\n";
    return 0;
}