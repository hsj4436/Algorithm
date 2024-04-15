#include <iostream>
#include <algorithm>

struct serial {
    std::string number;
    int sum;
    serial() {}
    serial(std::string number) {
        this->number = number;
        this->sum = 0;
        for (char ch : number) {
            if ('0' <= ch && ch <= '9') {
                this->sum += ch - '0';
            }
        }
    }
};

int N;
serial serials[51];


int main() {
    std::cin >> N;

    std::string number;
    for (int i = 0; i< N; i++) {
        std::cin >> number;
        serials[i] = serial(number);
    }

    std::sort(serials, serials + N, [&](serial a, serial b) {
       if (a.number.size() == b.number.size()) {
           if (a.sum == b.sum) {
               return a.number < b.number;
           } else {
               return a.sum < b.sum;
           }
       } else {
           return a.number.size() < b.number.size();
       }
    });

    for (int i = 0; i < N; i++) {
        std::cout << serials[i].number << "\n";
    }

    return 0;
}
