#include <iostream>
#include <map>

int N;
char G;
int game;
std::map<std::string, bool> map;

int main() {
    std::cin >> N >> G;

    if (G == 'Y') {
        game = 2;
    } else if (G == 'F') {
        game = 3;
    } else {
        game = 4;
    }

    std::string name;
    for (int i = 0; i < N; i++) {
        std::cin >> name;
        if (map[name]) {
            continue;
        }
        map[name] = true;
    }

    std::cout << map.size() / (game - 1) << "\n";
    return 0;
}
