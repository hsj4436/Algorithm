#include <iostream>
#include <algorithm>
#include <vector>

int N;
std::string arr;
bool used[51];
std::vector<int> origin;

bool back_track(int index) {
    if (index < 0) {
        if (origin.size() == N) {
            return true;
        } else {
            return false;
        }
    }

    if (index - 1 >= 0) {
        int n = (arr[index - 1] - '0') * 10 + (arr[index] - '0');
        if (n > 0 && n <= N && !used[n]) {
            used[n] = true;
            origin.push_back(n);
            if (back_track(index - 2)) {
                return true;
            }
            origin.pop_back();
            used[n] = false;
        }
    }

    int n = arr[index] - '0';
    if (n > 0 && n <= N && !used[n]) {
        used[n] = true;
        origin.push_back(n);
        if (back_track(index - 1)) {
            return true;
        }
        origin.pop_back();
        used[n] = false;
    }

    return false;
}

int main() {
    std::cin >> arr;

    if (arr.size() < 10) {
        N = arr.size();
    } else {
        N = 9;
        int size = 9;
        while (size != arr.size()) {
            N++;
            size += 2;
        }
    }

    back_track(arr.size() - 1);

    for (auto it = origin.rbegin(); it != origin.rend(); it++) {
        std::cout << *it << " ";
    }
    return 0;
}