#include <iostream>
#include <algorithm>

#define PII std::pair<int, int>

std::string N;

int main() {
    std::cin >> N;

    std::sort(N.begin(), N.end(), [&](char a, char b) {return a > b;});

    long long sum = 0;
    for (int i = 0; i < N.size(); i++) {
        sum += N[i] - '0';
    }
    
    if (sum % 3 == 0 && N[N.size() - 1] == '0') {
        std::cout << N << "\n";
    } else {
        std::cout << "-1\n";
    }

    return 0;
}