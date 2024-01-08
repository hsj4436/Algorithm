#include <iostream>
#include <vector>

int T;
int primes[2000001];
std::vector<int> v;
int main() {
    for (int i = 2; i < 2000001; i++) {
        primes[i] = i;
    }

    for (int i = 2; i < 2000001; i++) {
        if (primes[i] == 0) {
            continue;
        }
        for (int j = 2 * i; j < 2000001; j += i) {
            primes[j] = 0;
        }
    }
    
    for (int i = 2; i < 2000001; i++) {
        if (primes[i] != 0) {
            v.push_back(i);
        }
    }

    std::cin >> T;

    for (int tc = 0; tc < T; tc++) {
        long long a, b;
        std::cin >> a >> b;

        long long sum = a + b;
        if (sum == 2 || sum == 3) {
            std::cout << "NO\n";
        } else if (sum % 2 == 0) {
            std::cout << "YES\n";
        } else {
            sum -= 2;
            bool check = false;
            for (int i = 0; i < v.size() && (long long)v[i] * v[i] <= sum; i++) {
                if (sum % v[i] == 0) {
                    std::cout << "NO\n";
                    check = true;
                    break;
                }
            }
            if (!check) {
                std::cout << "YES\n";
            }
        }
    }
    return 0;
}
