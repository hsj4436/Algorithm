#include <iostream>

int N;
int day[7];
bool flag = false;

void dfs(int sum) {
    if (sum % 7 == 4) {
        flag = true;
        return;
    }
    
    for (int i = 1; i < 7; i++) {
        if (day[i] == 0) {
            continue;
        }
        day[i]--;
        dfs(sum + i);
        day[i]++;
    }
}


int main() {
    std::cin >> N;

    int a;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> a;
        if (a % 7 == 0) {
            continue;
        }
        day[a % 7]++;
        cnt++;
    }
    if (day[4] != 0) {
        std::cout << "YES\n";
        return 0;
    }

    dfs(0);
    
    if (flag) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    
    return 0;
}