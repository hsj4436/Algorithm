#include <iostream>
#include <map>
#include <set>

int N;
std::map<std::string, std::string> status;

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::string name, record;
        std::cin >> name >> record;
        status[name] = record;
    }

    std::set<std::string> names;

    for (auto p : status) {
        if (p.second == "enter") {
            names.insert(p.first);
        }
    }

    for (auto it = names.rbegin(); it != names.rend(); it++) {
        std::cout << *it << "\n";
    }

    return 0;
}
