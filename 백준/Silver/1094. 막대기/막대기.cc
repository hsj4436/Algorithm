#include <iostream>
#include <queue>

int X;

int main() {
    std::cin >> X;

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    pq.push(64);

    int totalLength = 64;
    while (totalLength != X) {
        int minLength = pq.top();

        if (totalLength - minLength / 2 >= X) {
            pq.pop();
            pq.push(minLength / 2);
            totalLength -= minLength / 2;
        } else {
            pq.pop();
            pq.push(minLength / 2);
            pq.push(minLength / 2);
        }
    }

    std::cout << pq.size() << "\n";
    return 0;
}
