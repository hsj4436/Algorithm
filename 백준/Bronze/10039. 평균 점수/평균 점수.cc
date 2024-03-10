#include <iostream>

int main() {
    int score;
    int average = 0;
    for (int i = 0; i < 5; i++) {
        std::cin >> score;
        if (score < 40) {
            average += 40;
        } else {
            average += score;
        }
    }
    
    std::cout << average / 5 << "\n";
    
    return 0;
}