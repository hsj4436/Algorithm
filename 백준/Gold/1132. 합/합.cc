#include <iostream>
#include <algorithm>
#include <math.h>

int N;
long long counts[10];
bool notBeZero[10];

int main() {
    std::cin >> N;

    std::string number;
    for (int i = 0; i < N; i++) {
        std::cin >> number;
        notBeZero[number[0] - 'A'] = true;
        for (int j = number.size() - 1; j > -1; j--) {
            counts[number[j] - 'A'] += (long long)std::pow(10, number.size() - 1 - j);
        }
    }
        
    bool allAlphabetAssigned = true;
    for (int i = 0; i < 10; i++) {
        if (counts[i] == 0) {
            allAlphabetAssigned = false;
        }
    }
    if (allAlphabetAssigned) {
        long long min = 100000000000000;
        int index = 0;
        for (int i = 0; i < 10; i++) {
            if (!notBeZero[i] && counts[i] < min) {
                min = counts[i];
                index = i;
            }
        }
        counts[index] = 0;
    }
    
    std::sort(counts, counts + 10, std::greater<>());
    
    long long answer = 0;
    for (int i = 0, j = 9; i < 10; i++, j--) {
        answer += counts[i] * j;
    }
    
    std::cout << answer << "\n";

    return 0;
}
