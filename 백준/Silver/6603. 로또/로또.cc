#include <iostream>
#include <vector>
#include <set>

int K;
int arr[13];
std::vector<int> selected;
std::set<std::vector<int>> answer;

void sol(int index, int cnt) {
    if (cnt == 6) {
        answer.insert(selected);
        return;
    }
    if (index == K) {
        return;
    }

    for (int i = index; i < K; i++) {
        selected.push_back(arr[i]);
        sol(i + 1, cnt + 1);
        selected.pop_back();
        sol(i + 1, cnt);
    }
}

int main() {
    while (true) {
        std::cin >> K;
        if (K == 0) {
            break;
        }
        for (int i = 0; i < K; i++) {
            std::cin >> arr[i];
        }

        sol(0, 0);

        for (auto v : answer) {
            for (auto i : v) {
                std::cout << i << " ";
            }
            std::cout << "\n";
        }
        answer.clear();
        std::cout << "\n";
    }
    return 0;
}
