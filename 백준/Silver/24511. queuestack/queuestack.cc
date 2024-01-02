#include <iostream>
#include <deque>

int types[100001];
std::deque<int>qs;

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;
    int type = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> type;
        types[i] = type;
    }
    int num;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        if (types[i] == 0) {
            qs.push_front(num);
        }
    }

    int M;
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> num;
        qs.push_back(num);
        std::cout << qs.front() << " ";
        qs.pop_front();
    }
    return 0;
}
