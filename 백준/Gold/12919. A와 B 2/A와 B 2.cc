#include <iostream>
#include <algorithm>
#include <queue>

std::string S, T;
int tA = 0, tB = 0;
int sA = 0, sB = 0;

bool dfs(std::string cur) {
    if (S == cur) {
        std::cout << "1\n";
        return true;
    }

    if (S.size() == cur.size()) {
        return false;
    }

    if (cur.back() == 'A') {
        cur.pop_back();
        if (dfs(cur)) {
            return true;
        }
        cur.push_back('A');
    }

    if (cur[0] == 'B') {
        cur.erase(cur.begin());
        std::reverse(cur.begin(), cur.end());
        if (dfs(cur)) {
            return true;
        }
    }

    return false;
}

int main() {
    std::cin >> S >> T;

    for (int i = 0; i < T.size(); i++) {
        if (T[i] == 'A') {
            tA++;
        } else {
            tB++;
        }
    }

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'A') {
            sA++;
        } else {
            sB++;
        }
    }

    if (sA > tA || sB > tB) {
        std::cout << "0\n";
        return 0;
    }

    if (!dfs(T)) {
        std::cout << "0\n";
    }

    return 0;
}