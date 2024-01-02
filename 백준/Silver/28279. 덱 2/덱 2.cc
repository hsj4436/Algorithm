#include <iostream>
#include <list>

int N;
std::list<int> deq;

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        int c, n;
        std::cin >> c;
        switch (c) {
            case 1:
                std::cin >> n;
                deq.push_front(n);
                break;
            case 2:
                std::cin >> n;
                deq.push_back(n);
                break;
            case 3: {
                if (deq.empty()) {
                    std::cout << "-1\n";
                } else {
                    std::cout << deq.front() << "\n";
                    deq.pop_front();
                }
                break;
            }
            case 4: {
                if (deq.empty()) {
                    std::cout << "-1\n";
                } else {
                    std::cout << deq.back() << "\n";
                    deq.pop_back();
                }
                break;
            }
            case 5:
                std::cout << deq.size() << "\n";
                break;
            case 6:
                if (deq.empty()) {
                    std::cout << "1\n";
                } else {
                    std::cout << "0\n";
                }
                break;
            case 7:
                if (deq.empty()) {
                    std::cout << "-1\n";
                } else {
                    std::cout << deq.front() << "\n";
                }
                break;
            case 8:
                if (deq.empty()) {
                    std::cout << "-1\n";
                } else {
                    std::cout << deq.back() << "\n";
                }
                break;
        }
    }
    return 0;
}
